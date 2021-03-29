#include "PersistenceEngineFromCsv.h"
#include <fstream>
#include <sstream>

PersistenceEngineFromCsv::PersistenceEngineFromCsv(){

}

void PersistenceEngineFromCsv::load(std::string filepath, std::vector<Book *>& books){
    std::fstream fin;
    fin.open(filepath);
    if(!fin.is_open()) throw IOException();
    books.clear();
    int iterator = 0;
    std::string line;
    while(std::getline(fin,line)){
        std::string title;
        std::string author;
        std::string gen;
        int temp;
        Genre genre;
        std::string description;
        std::string pubY;
        int publicationYear;
        std::string cover;

        std::stringstream ss(line);
        std::getline(ss, title, ',');
        std::getline(ss, author, ',');
        std::getline(ss, gen, ',');
        std::getline(ss, description, ',');
        std::getline(ss, pubY, ',');
        std::getline(ss, cover, ',');

        temp = std::stoi(gen);
        genre = static_cast<Genre>(temp);
        publicationYear = std::stoi(pubY);

        //todo: redo whatever this is ^

        Book* book = new Book(title,author,genre,description,publicationYear,cover);
        books.push_back(book);
        iterator++;
    }
}

void PersistenceEngineFromCsv::save(std::string filepath, std::vector<Book *>& books){
    std::fstream fout;
    fout.open(filepath);
    for(int iterator=0;iterator <= books.size(); iterator ++){
        Book* book = books.at(iterator);
        fout<<book->getTitle()<<","<<book->getAuthor()<<","<<std::to_string(book->getGenre())<<","<<book->getDescription()<<","<<std::to_string(book->getPublicationYear())<<","<<book->getCover()<<'\n';
    }
fout.close();
}
