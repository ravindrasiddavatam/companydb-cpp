CXXFLAGS=-g --std=c++20

companydb: companydb.o Company.o Purchase.o Person.o Customer.o Employee.o
	g++ -o $@ $^ $(CXXFLAGS)

companydb.o: companydb.cpp
	g++ -c -o $@ companydb.cpp $(CXXFLAGS)

Customer.o: Customer.cpp Customer.h
	g++ -c -o $@ Customer.cpp $(CXXFLAGS)

Company.o: Company.cpp Company.h
	g++ -c -o $@ Company.cpp $(CXXFLAGS)

Employee.o: Employee.cpp Employee.h
	g++ -c -o $@ Employee.cpp $(CXXFLAGS)

Purchase.o: Purchase.cpp Purchase.h
	g++ -c -o $@ Purchase.cpp $(CXXFLAGS)

Person.o: Person.cpp Person.h
	g++ -c -o $@ Person.cpp $(CXXFLAGS)

clean:
	rm -f *.o companydb