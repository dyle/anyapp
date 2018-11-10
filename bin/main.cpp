/*
 * This file is part of anyapp.
 * See the LICENSE file for the software license.
 * (C) Copyright 2018, Oliver Maurhart, dyle71@gmail.com
 */


#include <iostream>

#include <boost/program_options.hpp>

#include <QApplication>

#include "mainwindow.hpp"


#define PROGRAM_DESCRIPTION "\
This is the application boilerplate template anyapp.\n\
\n\
Copyright (C) 2018 Oliver Maurhart, <dyle71@gmail.com>\n\
Licenseed under the GNU General Public License 3\n\
See: http://www.gnu.org/licenses/ for details."


/**
 * Parses the command line and places found options and arguments in the boost variables map.
 *
 * @param   programOptions      This will hold the found values of the parsed command line.
 * @param   argc                Number of command line arguments (as usual from main()).
 * @param   argv                Command line arguments (as usual from main()).
 * @return  true, if we managed to sucessfuly parse the command line and should proceed.
 */
bool parseCommandLine(boost::program_options::variables_map & programOptions, int argc, char ** argv);


int main(int argc, char ** argv) {

    boost::program_options::variables_map programOptions;
    if (!parseCommandLine(programOptions, argc, argv)) {
        return 0;
    }

    QApplication application{argc, argv};
    application.setOrganizationName("Oliver Maurhart <dyle71@gmail.com>");
    application.setOrganizationDomain("");
    application.setApplicationName("AnyApp");
    application.setApplicationVersion(VERSION);

    anyapp::MainWindow mainWindow;
    mainWindow.show();

    return application.exec();
}


bool parseCommandLine(boost::program_options::variables_map & programOptions, int argc, char ** argv) {

    auto applicationHeader = std::string{"anyapp - Dyle's AnyApplication Template V"} + VERSION;
    auto description = std::string{PROGRAM_DESCRIPTION};
    auto synopsis = std::string{"Usage: "} + argv[0] + " FILE";

    auto optionsLine = applicationHeader + "\n" + description + "\n\n" + synopsis + "\n\nAllowed Options";
    boost::program_options::options_description options{optionsLine};
    options.add_options()("help,h", "this page");
    options.add_options()("version,v", "print version string");

    boost::program_options::options_description arguments{"Arguments"};
    arguments.add_options()("FILE", "file to open");
    boost::program_options::positional_options_description positionalArgumentDescriptions;
    positionalArgumentDescriptions.add("FILE", 1);

    boost::program_options::options_description commandLineOptions{"Command Line"};
    commandLineOptions.add(options);
    commandLineOptions.add(arguments);

    try {
        boost::program_options::command_line_parser parser{argc, reinterpret_cast<char const * const *>(argv)};
        boost::program_options::store(
                parser.options(commandLineOptions).positional(positionalArgumentDescriptions).run(),
                programOptions);
        boost::program_options::notify(programOptions);
    }
    catch (std::exception & exception) {
        std::cerr << "error parsing command line: " <<  exception.what()
                  << "\ntype '--help' for help"
                  << std::endl;
        std::exit(1);
    }

    if (programOptions.count("help")) {
        std::cout << options << std::endl;
        std::cout << "FILE: " << arguments.find("FILE", false).description()
                  << "\n"
                  << std::endl;
        return false;
    }

    if (programOptions.count("version")) {
        std::cout << applicationHeader << std::endl;
        return false;
    }

    return true;
}

