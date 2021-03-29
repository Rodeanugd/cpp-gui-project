#include "test.h"
#include <assert.h>

void testBook() {
    std::string testTitle = "TestTitle";
    std::string testAuthor = "testAuthor";
    std::string testDescription = "TestDescription";
    std::string testCover = "TestCover";
    Genre testGenre = other;
    int testYear = 2020;

    Book testBook(testTitle, testAuthor, testGenre, testDescription, testYear, testCover);
    assert(testBook.getAuthor() == testAuthor);
    assert(testBook.getTitle() == testTitle);
    assert(testBook.getGenre() == testGenre);
    assert(testBook.getPublicationYear() == testYear);
    assert(testBook.getDescription() == testDescription);
    assert(testBook.getCover() == testCover);
}
void testRepo() {
    std::string testTitle = "TestTitle";
    std::string testAuthor = "testAuthor";
    std::string testDescription = "TestDescription";
    std::string testCover = "TestCover";
    Genre testGenre = other;
    int testYear = 2020;

    std::string testTitle2 = "TestTitle2";
    std::string testAuthor2 = "testAuthor2";
    std::string testDescription2 = "TestDescription2";
    std::string testCover2 = "TestCover2";
    Genre testGenre2 = drama;
    int testYear2 = 20202;

    std::string testString;

    BookRepo tRepo;
    Book testBook(testTitle, testAuthor, testGenre, testDescription, testYear, testCover);
    Book testBook2(testTitle2, testAuthor2, testGenre2, testDescription2, testYear2, testCover2);

    assert(tRepo.addBook(&testBook) == 1);
    assert(tRepo.addBook(&testBook) == 0);
    assert(tRepo.addBook(&testBook2) == 1);

    assert(tRepo.removeBook(0) == 1);
    assert(tRepo.removeBook(2) == 0);

    assert(tRepo.searchBook(&testBook) == -1);
    assert(tRepo.searchBook(&testBook2) == 0);

    assert(tRepo.updateBook(2,&testBook2) == 0);
    assert(tRepo.updateBook(0, &testBook2) == 1);

    assert(tRepo.displayBook(&testString,2) == 0);
    assert(tRepo.displayBook(&testString, 0) == 1);
}
void testController() {

}


void test() {
    testBook();
    testRepo();
    testController();
}
