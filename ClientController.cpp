#include "ClientController.h"
#include "UserInterface.h"
#include <string>

ClientController::ClientController() {

}
ClientController::ClientController(BookRepo repo, BookRepo toListen) {
    this->repo = repo;
    this->toListen = toListen;
}
ClientController::~ClientController() {

}

void ClientController::LoadBooks() {
    Book* a = new Book("asd", "rg", drama, "rtngfv", 1, "re");
    Book* b = new Book("abc", "bf", drama, "gdnb cv", 2, "fbvdcx");
    Book* c = new Book("dsd", "fb", nonfiction, "dfb vc", 3, "fdbdfb");
    Book* d = new Book("gsd", "bf", fantasy, "pldfb cm", 4, "dfbndn");
    Book* e = new Book("cxv", "fb", thriller, "df v", 5, "xcbdn");
    Book* f = new Book("erw", "r3", fantasy, "sbsfb", 6, "fbd");
    Book* g = new Book("jyrt", "gfbrg", other, "drbd", 7, "erheh");
    Book* h = new Book("bvc", "rg", other, "rbdb", 8, "dfdn");
    Book* i = new Book("dsfb", "fb", thriller, "pdfbdfblm", 9, "dfbdn");
    Book* j = new Book("jrdrr", "bf", drama, "pldfbdfbm", 10, "jyrk");

    this->addBook(a);
    this->addBook(b);
    this->addBook(c);
    this->addBook(d);
    this->addBook(e);
    this->addBook(f);
    this->addBook(g);
    this->addBook(h);
    this->addBook(i);
    this->addBook(j);
}

bool ClientController::displayBook(std::string* display, int index) {
    return this->repo.displayBook(display, index);
}
bool ClientController::displayBookTL(std::string* display, int index) {
    return this->toListen.displayBook(display, index);
}

bool ClientController::load(std::string filepath)
{
    std::string extension;
    PersistenceEngine* persistence;

    extension = filepath.substr(filepath.find(".")+1,filepath.length());

    if(extension == "json"){
        persistence = new PersistenceEngineFromJson();
    }
    else if(extension == "csv"){
        persistence = new PersistenceEngineFromCsv();
    }
    else{
        return false;
        //exception(?)
    }
    persistence->load(filepath,this->repo.vector);
    return true;


}

bool ClientController::save(std::string filepath)
{
    std::string extension;
    PersistenceEngine* persistence;

    extension = filepath.substr(filepath.find(".")+1,filepath.length());

    if(extension == "json"){
        persistence = new PersistenceEngineFromJson();
    }
    else if(extension == "csv"){
        persistence = new PersistenceEngineFromCsv();
    }
    else{
        return false;
        //exception(?)
    }
    persistence->save(filepath,this->repo.vector);
    return true;


}

bool ClientController::undo(){
    bool ret = 0;
    if(!this->undoStack.empty()){
        operation o;
        o=this->undoStack.top();
        if(o.type == 1){
            //_sleep(5000);
            ret = this->removeBook(o.position);
            if (ret == 1){
                this->undoStack.pop();
                this->undoStack.pop();
                this->redoStack.push(o);
            }
        }
        else if(o.type == 2){
            ret = this->addBook(o.book);
            if(ret == 1){
                this->undoStack.pop();
                this->undoStack.pop();
                this->redoStack.push(o);
            }
        }
        else if (o.type == 3){
            ret = this->updateBook(o.position,o.book);
            if(ret==1){
                this->undoStack.pop();
                this->undoStack.pop();
                this->redoStack.push(o);
            }
        }
    }
    return ret;
}

bool ClientController::redo()
{
    bool ret = 0;
        if (!this->redoStack.empty()) {
            operation o;
            o = this->redoStack.top();
            if (o.type == 1) {
                ret = this->addBook(o.book);
                if (ret == 1) {
                    this->redoStack.pop();
                    this->undoStack.push(o);
                }
            }
            else if (o.type == 2) {
                ret = this->removeBook(o.position);
                if (ret == 1) {
                    this->redoStack.pop();
                    this->undoStack.push(o);
                }
            }
            if (o.type == 3) {
                ret = this->updateBook(o.position,o.former);
                if (ret == 1) {
                    this->redoStack.pop();
                    this->undoStack.push(o);
                }
            }
        }
        return ret;
}

bool ClientController::addBook(Book* book) {
    if( this->repo.addBook(book)){
        operation op;
        op.type = 1;
        op.position = this->repo.searchBook(book);
        op.book = book;
        this->undoStack.push(op);
        return true;
    }
    return false;
}

bool ClientController::addBookTL(Book* book) {
    return this->toListen.addBook(book);
}

bool ClientController::removeBook(int index) {
    operation op;
    op.book = this->repo.vector.at(index);
    if( this->repo.removeBook(index)){

        op.type = 2;
        op.position = index;
        this->undoStack.push(op);
        return true;
    }
    return false;
}
bool ClientController::removeBookTL(int index) {
    return this->toListen.removeBook(index);
}


bool ClientController::updateBook(int index, Book* book) {
            operation op;
            op.book=this->repo.vector.at(index);
    if( this->repo.updateBook(index, book)){

        op.type = 3;
        op.position=index;
        op.former = book;
        this->undoStack.push(op);
        return true;
    }
    return false;
}


//void ClientController::displayBooksByGenre(int genre) {
//	int iterator = 0;
//	while (iterator < this->repo.vector.size()) {
//		if (genre == this->repo.vector.at(iterator)->getGenre)
//			displayBook(iterator);
//	}
//
//}
