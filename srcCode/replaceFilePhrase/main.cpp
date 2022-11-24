#include <stdio.h>
#include <string.h>

#include <fstream>
#include <iostream>
#include <string>

size_t getFileSize( FILE** fp, const char* filePath ) {
    *fp = fopen( filePath, "r" );
    if ( *fp == NULL ) {
        fprintf( stderr, "%s does not exist!\n", filePath );
        exit( 1 );
    }
    int count = 0;
    int c = 0;

    while ( ( c = fgetc( *fp ) ) != EOF ) {
        ++count;
    }
    rewind( *fp );
    return ++count;
}

void getFileText( char* destination, size_t buffer_size, FILE** fp ) {
    fread( destination, buffer_size, 1, *fp );
    destination[buffer_size - 1] = '\0';
    fclose( *fp );
    *fp = NULL;
}

std::string txtFileToString( const char* filepath ) {
    FILE* fp;
    size_t buffer_size = getFileSize( &fp, filepath );
    char shaderCode[buffer_size];
    getFileText( shaderCode, buffer_size, &fp );
    std::string str( shaderCode );
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