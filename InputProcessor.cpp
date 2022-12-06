// Jason Nguyen + Thaddeus Gonzalez-Serna
// HW 5

#include "InputProcessor.h"

// Constructor
InputProcessor::InputProcessor() = default;


// Process movies and sets up correct movie files
void InputProcessor::processMovies(std::set<Movie *> movies[]) {
    std::fstream input;
    input.open("data4movies.txt");
    while (!input.eof()) {
        std::string read_input;
        std::getline(input, read_input);
        std::stringstream line_input(read_input);
        getline(line_input, read_input, ',');
        char type = read_input[0];

        Movie* temp = MovieFactory::createMovie(type);

        if (temp) {
            getline(line_input, read_input, ',');
            int stock = atoi(read_input.c_str());

            temp->setStock(stock);
           line_input.get();
            getline(line_input, read_input, ',');
            std::string director = read_input;

            temp->setDirector(director);

            line_input.get();
            getline(line_input, read_input, ',');
            std::string title = read_input;

            temp->setTitle(title);

            line_input.get();
            getline(line_input, read_input, ',');
            std::string year = read_input;

            year.resize(year.size());

            if (temp->getChar() == 'F' || temp->getChar() == 'D' ) { // For non-classic movies
                year = year.substr(0, year.size()-1);
                std::cout << "year" << year<<"X"<<std::endl;
                temp->setYear(year);

            } else { // For classic movies
                //year = year.substr(0, year.size()-4);
                std::string release_date = getDate(year);
                temp->setReleaseDate(release_date);

                std::string actor = getActor(year);
                temp->setActor(actor);
                
            }


            std::set<Movie*>::iterator it;
            Movie* temp_movie_comparator;
            switch (temp->getChar()) {
                case COMEDY:
                    movies[COMEDY_ENUM].insert(temp);
                    break;
                case CLASSIC:
                    it = movies[CLASSICS_ENUM].begin();
                    for (; it != movies[CLASSICS_ENUM].end(); it++) {
                        temp_movie_comparator = *it;
                        if (*temp == *temp_movie_comparator){
                            temp->setOtherMovie(temp_movie_comparator);
                            temp_movie_comparator->setOtherMovie(temp);
                        }
                    }

                    movies[CLASSICS_ENUM].insert(temp);
                    break;
                case DRAMA:
                    movies[DRAMA_ENUM].insert(temp);
                    break;
                default:
                    break;
            }
        }

    }
    input.close();
}

// Process customers and sets up respective attributes
void InputProcessor::processCustomers(HashTable<Customer> &customerContainer) {
    std::fstream input;
    input.open("data4customers.txt");
    Customer* customer;
    while (!input.eof()) {
        std::string id; 
        std::string l_name;
        std::string f_name;

        input >> id;
        input >> l_name;
        input >> f_name;
        customer = new Customer(f_name, l_name, id);
        customerContainer.insert(customer);
    }
    input.close();
}

// Process commands to execute
void InputProcessor::processCommands(std::set<Movie *> movies[], HashTable<Customer> &customers) {
    if (movies == nullptr) {
        return;
    }

    std::fstream input;
    input.open("data4commands.txt");
    std::string read_input;

    while (!input.eof()) {
        getline(input, read_input);
        std::stringstream line_input(read_input);

        Transaction* transaction = TransactionFactory::createTransaction(line_input, movies, customers);
        if (transaction) {
            transaction->execute();
        }
        delete transaction;
    }
    input.close();
}

//retieve date from line
std::string InputProcessor::getDate(const std::string & input) {
   
    
    std::string ret_val;
    std::string temp = input.substr(getActor(input).size());

    ret_val = temp.substr(0, temp.size()-1);
  
    if(ret_val[0]==' '){
        ret_val = ret_val.substr(1);
    }
    
    return ret_val;
}

//reteive actor from a line
    std::string InputProcessor::getActor(const std::string & input) {

    std::string ret_val;
    int space_count = 0;

    for(int i=0 ;space_count< 2;i++){

       if(input[i]== ' '){
           space_count++;
           ret_val.push_back(' ');
       }else{
           ret_val.push_back(input[i]);
       }

   }//for loop closer

    ret_val = ret_val.substr(0, ret_val.size()-1);

    return ret_val;
}
