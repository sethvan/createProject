/*
        Copyright 2022 Seth Van Hankins

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
/*
    This cpp file creates the replacePhrase executable.
    replacePhrase is a command that takes in a filepath, searches the file text
    for a pattern string and substitutes it with a replacement string and then
    outputs the mutated version to the output filepath that was specified.
    Args to command line = inputFilepath, patternString, replacementString, outputFilepath

    It's main intended purpose is to fill in pertinent fields of template
    files created by the user. Placeholder strings are  positioned inside the
    templates to be populated by input to the apps created by user.
*/

#include <stdio.h>
#include <string.h>

#include <fstream>
#include <iostream>
#include <string>

void openFile( FILE** fp, const char* filePath ) {
    *fp = fopen( filePath, "r" );
    if ( *fp == NULL ) {
        fprintf( stderr, "%s does not exist!\n", filePath );
        exit( 1 );
    }
}

size_t getFileSize( FILE** fp ) {
    int count = 0;
    int c = 0;

    while ( ( c = fgetc( *fp ) ) != EOF ) {
        ++count;
    }
    rewind( *fp );
    return ++count;
}

void getTextAndCloseFile( char* destination, size_t buffer_size, FILE** fp ) {
    fread( destination, buffer_size, 1, *fp );
    destination[buffer_size - 1] = '\0';
    fclose( *fp );
    *fp = NULL;
}

std::string txtFileToString( const char* filepath ) {
    FILE* fp;
    openFile( &fp, filepath );
    size_t buffer_size = getFileSize( &fp );
    char fileText[buffer_size];
    getTextAndCloseFile( fileText, buffer_size, &fp );
    std::string str( fileText );
    return str;
}

// from https://stackoverflow.com/questions/4643512/replace-substring-with-another-substring-c/14678946#14678946
void replaceStringInPlace( std::string& subject, const std::string& search, const std::string& replace ) {
    size_t pos = 0;
    while ( ( pos = subject.find( search, pos ) ) != std::string::npos ) {
        subject.replace( pos, search.length(), replace );
        pos += replace.length();
    }
}

int main( int c, char* argv[] ) {
    std::string subject = txtFileToString( argv[1] );
    std::string search( argv[2] );
    std::string replace( argv[3] );
    const char* outputFilePath = argv[4];

    replaceStringInPlace( subject, search, replace );
    std::ofstream out( outputFilePath );
    out << subject;
    out.close();
}
