
#include <iostream>
#include <string>

using namespace std;

const int SIZE = 100;

class Animal{
private:
	int animalId;
	int age;
	string kind;
	string name;
	int pawsNum;
	int helth;
	bool isShow;
public:
    Animal() {
        animalId = 0;
        age = 0;
        kind[20];
        name[20];
        pawsNum = 0;
        helth = 0;
        isShow = false;
    }

	unsigned int getAnimalId() const{
	    return animalId;
    }
	void setAnimalId(const unsigned int &animalNumber);

	unsigned int getAge() const{
	    return age;
    }
	void setAge(const unsigned int &ageOfAnimal);

	string getKind(){
	    return kind;
    }
	void setKind(string &kindOfAnimal);

	string getName(){
	    return name;
    }
	void setName(string nameOfAnimal);

	unsigned int getPawsNum() const{
        return pawsNum;
	}
	void setPawsNum(const unsigned int &pawsNumber);

	unsigned int getHelth() const{
        return helth;
	}
	void setHelth(const unsigned int &helthStatus);

	bool getIsShow() const{
        return isShow;
	}
	void setIsShow(const bool &isShowAnimal);
};

class Zoo {
public:
	int animalCount;
	Animal* animals[SIZE];
    //animals, that are in zoo
	void createZoo(){
		// add tiger
		Animal* curAnimal1 = new Animal();
		curAnimal1->setAnimalId(1);
		curAnimal1->setAge(10);
		string curKind = "tiger";
		curAnimal1->setKind(curKind);
		string curName = "Oskar";
		curAnimal1->setName(curName);
		curAnimal1->setPawsNum(4);
		curAnimal1->setHelth(95);
		curAnimal1->setIsShow(true);
		animals[0] = curAnimal1;

		// add elephant
		Animal* curAnimal2 = new Animal();
		curAnimal2->setAnimalId(2);
		curAnimal2->setAge(15);
		curKind = "elephant";
		curAnimal2->setKind(curKind);
		curName = "Tom";
		curAnimal2->setName(curName);
		curAnimal2->setPawsNum(4);
		curAnimal2->setHelth(100);
		curAnimal2->setIsShow(true);
		animals[1] = curAnimal2;

		// add giraffe
		Animal* curAnimal3 = new Animal();
		curAnimal3->setAnimalId(3);
		curAnimal3->setAge(7);
		curKind = "giraffe";
		curAnimal3->setKind(curKind);
		curName = "Marti";
		curAnimal3->setName(curName);
		curAnimal3->setPawsNum(4);
		curAnimal3->setHelth(92);
		curAnimal3->setIsShow(false);
		animals[2] = curAnimal3;
		animalCount = 3;
	}
};

class ZooManager {
public:
	Zoo* zoo = new Zoo();

	void addNewAnimal(){
		Animal* newAnimal = new Animal();
		int curAge;
		string curKind = new char[20];
		string curName = new char[20];
		int curPawsNum;
		int curHelth;
		bool curIsShow;

		cout << "Enter kind of animal: ";
		cin >> curKind;
		cout << "Enter name of animal: ";
		cin >> curName;
		cout << "Enter age of animal: ";
		cin >> curAge;
		cout << "Enter number of paws: ";
		cin >> curPawsNum;
		cout << "Enter status of helth: ";
		cin >> curHelth;
		cout << "Is this animal on show? (1 - on show, 0 - not on show): ";
		cin >> curIsShow;
		newAnimal->setAnimalId(zoo->animalCount + 1);
		newAnimal->setKind(curKind);
		newAnimal->setName(curName);
		newAnimal->setAge(curAge);
		newAnimal->setPawsNum(curPawsNum);
		newAnimal->setHelth(curHelth);
		newAnimal->setIsShow(curIsShow);
		zoo->animals[zoo->animalCount] = newAnimal;
		zoo->animalCount++;

	}
	void deleteAnimal(int anId2){

		for (int i = anId2; i < zoo->animalCount; i++){
			zoo->animals[i - 1] = zoo->animals[i];
			zoo->animals[i - 1]->setAnimalId(i);
		}

		zoo->animalCount--;
	}
	void showPopulation(){
		if (zoo->animalCount > 0){
			for (int i = 0; i < zoo->animalCount; i++){
				cout << zoo->animals[i]->getAnimalId() << " " << zoo->animals[i]->getKind() << " " << zoo->animals[i]->getName() << endl;
			}
		}
		else
			cout << "Zoo is empty" << endl;
	};

	void showAboutInfo(int anId){
		int curId = zoo->animals[anId - 1]->getAnimalId();
		int curAge = zoo->animals[anId - 1]->getAge();
		string curKind = zoo->animals[anId - 1]->getKind();
		string curName = zoo->animals[anId - 1]->getName();
        int curPawsNum = zoo->animals[anId - 1]->getPawsNum();
        int curHelth = zoo->animals[anId - 1]->getHelth();
        bool curIsShow = zoo->animals[anId - 1]->getIsShow();

		cout << "Id: " << curId << endl;
		cout << "Age: " << curAge << endl;
		cout << "Kind: " << curKind << endl;
		cout << "Name: " << curName << endl;
		cout << "Number of paws: " << curPawsNum << endl;
		cout << "Status of helth (in %): " << curHelth << endl;
		cout << "Animal is on show(1 - is on show, 0 - not on show): " << curIsShow << endl;
	};

	void editAnimalInfo(int anId2){
	    Animal* editAnimal = new Animal();

		int curAge;
		string curKind = new char[20];
		string curName = new char[20];
		int curPawsNum;
		int curHelth;
		bool curIsShow;

		cout << "Enter kind of animal: ";
		cin >> curKind;
		cout << "Enter name of animal: ";
		cin >> curName;
		cout << "Enter age of animal: ";
		cin >> curAge;
		cout << "Enter number of paws: ";
		cin >> curPawsNum;
		cout << "Enter status of helth: ";
		cin >> curHelth;
		cout << "Is this animal on show? (1 - on show, 0 - not on show): ";
		cin >> curIsShow;

		editAnimal->setAnimalId(anId2);
		editAnimal->setKind(curKind);
		editAnimal->setName(curName);
		editAnimal->setAge(curAge);
		editAnimal->setPawsNum(curPawsNum);
		editAnimal->setHelth(curHelth);
		editAnimal->setIsShow(curIsShow);
		zoo->animals[anId2-1] = editAnimal;
	};

	void showAboutEditedInfo(int anId2){
		int curId = zoo->animals[anId2 - 1]->getAnimalId();
		int curAge = zoo->animals[anId2 - 1]->getAge();
		string curKind = zoo->animals[anId2 - 1]->getKind();
		string curName = zoo->animals[anId2 - 1]->getName();
        int curPawsNum = zoo->animals[anId2 - 1]->getPawsNum();
        int curHelth = zoo->animals[anId2 - 1]->getHelth();
        bool curIsShow = zoo->animals[anId2 - 1]->getIsShow();

		cout << "Id: " << curId << endl;
		cout << "Age: " << curAge << endl;
		cout << "Kind: " << curKind << endl;
		cout << "Name: " << curName << endl;
		cout << "Number of paws: " << curPawsNum << endl;
		cout << "Status of helth (in %): " << curHelth << endl;
		cout << "Animal is on show(1 - is on show, 0 - not on show): " << curIsShow << endl;
	};
	void showUserMenu();
};

void Animal::setAnimalId(const unsigned int &animalNumber){
	animalId = animalNumber;
}

void Animal::setAge(const unsigned int &ageOfAnimal){
	age = ageOfAnimal;
}

void Animal::setKind(string &kindOfAnimal){
	kind = kindOfAnimal;
}

void Animal::setName(string nameOfAnimal){
	name = nameOfAnimal;
}

void Animal::setPawsNum(const unsigned int &pawsNumber){
	pawsNum = pawsNumber;
}

void Animal::setHelth(const unsigned int &helthStatus){
	helth = helthStatus;
}

void Animal::setIsShow(const bool &isShowAnimal){
	isShow = isShowAnimal;
}

void ZooManager::showUserMenu(){
	cout << "Welcome to zoo!\n\n";

	cout << "Select an action:" << endl;
	cout << "1. Show population of animals\n";
	cout << "2. Show info about animal\n";
	cout << "3. Edit info about animal\n";
	cout << "4. Add new animal\n";
	cout << "5. Delete animal\n";
	cout << "6. Exit\n";
}

int main(){
	ZooManager* zm = new ZooManager();
	// animals, that are in zoo
	zm->zoo->createZoo();
	zm->showUserMenu();
	int select;

	do{

		do{
			cin >> select;
			if (select < 1 || select > 6) cout << "Enter right number";
		} while (select < 1 || select > 6);

		switch (select){
		case 1: zm->showPopulation();
			break;

		case 2: {
			int anId;
			cout << "Enter number of animal: ";
			cin >> anId;
			if (anId >= 1 && anId <= zm->zoo->animalCount)
				zm->showAboutInfo(anId);
			else
				cout << "Error! Animal with number: " << anId << " is not in zoo";

			break;
		}

		case 3: {
		    int anId2;
		    cout << "Enter number of animal: ";
			cin >> anId2;
			if (anId2 >= 1 && anId2 <= zm->zoo->animalCount)
				zm->editAnimalInfo(anId2);
		    else
				cout << "Error! Animal with number: " << anId2 << " is not in zoo";
            zm->showAboutEditedInfo(anId2);

			break;
		}

		case 4: {
			zm->addNewAnimal();
			cout << "The animal added: " << endl;
			zm->showAboutInfo(zm->zoo->animalCount);
			break;
		}

		case 5: {
					int anId2;
					cout << "Enter number of animal: ";
					cin >> anId2;
					if (anId2 >= 1 && anId2 <= zm->zoo->animalCount){
						zm->deleteAnimal(anId2);
						zm->showPopulation();
					}
					else
						cout << "Error! Animal with number: " << anId2 << " is not in zoo" << endl;

					break;
		}

		default:
			cout << "\nGood bye!";
			break;
		}

	} while (select != 6);

	return 0;
}
