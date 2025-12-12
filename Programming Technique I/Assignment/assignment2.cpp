//Group member:1. GAN MEI LEE A25CS0225    2.EDWIN WONG JIIG HAO A25CS0215
//DATE:12/12/2025
#include <iostream>
#include <cctype>
using namespace std;

//user-defined function to ensure that the value of age entered by user is from 15 to 80
bool ageValid(int age){
    if(age>14&&age<81)//use if-else to return true if the age entered in the range
        return true;
    else //to return false if the age entered is not in the range
        return false;
}

//user-defined function to ensure that the gender entered by user either male(M) or female(F)
bool genderValid(char gender){
    if(gender=='F'||gender=='M')//use if-else to return true if the gender entered is valid
        return true;
    else //return false if the gender entered is invalid
        return false;
}

//user-defined function to calculate the BMR of Male
double calcMale(double weight,double height,int age){
    double BMR=(10*weight)+(6.25*height)-(5*age)+5;
    return BMR;
}

//user-defined function to calculate the BMR of Female
double calcFemale(double weight,double height,int age){
    double BMR=(10*weight)+(6.25*height)-(5*age)-161;
    return BMR;
}

int main(){
    //declare all the variable
    int age,sedentarycalorie,Exercise1to3calorie,Exercise4to5calorie,dailycalorie,intensecalories,Vintensecalorie;;
    bool status;
    char gender,newinput;
    double height,weight,BMR;
    
    //using do...while loop to accept user input repeatly
    do{
    cout<<"Basal metabolic Rate (BMR) Calculator \n\n";

    //using do..while loop to accept user input repeatly if the age entered is invalid
    do{
        cout<<"Age [15-80]: ";//prompt user to enetr the age
        cin>>age;//read the age entered by user
        status=ageValid(age);//ask user-defined function to check the validity of age entered
    }while(!status);
    
    //using do...while loop to accept user iout repeatly if the gender entered is invalid
    do{
    cout<<"Gender (F @ M): ";//prompt user to enter the gender
    cin>>gender;//read the gender entered by user
    gender=toupper(gender);//to ensure that the gender is in capital letter
    status=genderValid(gender);//ask user-defined function to check the validity of gender entered
    }while(!status);
    
    cout<<"Height (cm): ";//prompt user to enter height
    cin>>height;//read the height entered by user
    cout<<"Weight (kg): ";//prompt user to enter weight
    cin>>weight;//read the weight entered by user

    
    if(gender=='M')//use if-else to select to calculate the male's BMR or female's BMR
        BMR=calcMale(weight,height,age);//ask user-defined function to calculate the male's BMR
    else
         BMR=calcFemale(weight,height,age);//ask user defined function to calculate the female's BMR
    cout<<"\nBMR = "<<BMR<<" Calories/ day (using Mifflin-St Joer Equation)\n\n";//display the BMR calculated

    sedentarycalorie=BMR*1.2;//calculate the calories need if the activity level is Sedentary: little or no exercise
    Exercise1to3calorie=BMR*1.375;//calculate the calories need if the activity level is Exercise 1-3 times/week
    Exercise4to5calorie=BMR*1.465;//calculate the calories need if the activity level is Exercise 4-5 times/week
    dailycalorie=BMR*1.55;//calculate the calories need if the activity level is Daily exercise or intense exrcise 3-4 times/week
    intensecalories=BMR*1.725;//calculate the calories need if the activity level is Intense exercise 6-7 times/week
    Vintensecalorie=BMR*1.9;//calculate the calories need if the activity level is Very intense exercise daily, or physical job

    //display the calorie needs based on the activity level
    cout<<"\nDaily calorie needs base on activity level\n\n";
    cout<<"Activity Level\t\t\t\t\t Calorie"<<endl;
    cout<<"Sedentary: little or no exercise\t\t "<<sedentarycalorie;
    cout<<"\nExercise 1-3 times/week\t\t\t\t "<<Exercise1to3calorie;
    cout<<"\nExercise 4-5 times/week\t\t\t\t "<<Exercise4to5calorie;
    cout<<"\nDaily exercise or intense exrcise 3-4 times/week "<<dailycalorie;
    cout<<"\nIntense exercise 6-7 times/week\t\t\t "<<intensecalories;
    cout<<"\nVery intense exercise daily, or physical job\t "<<Vintensecalorie;
    cout<<"\n\nExercise: 15-30 miutes of elevated heart rate activity.";
    cout<<"\nIntense exercise: 45-120 minutes of elevated heart rate activiy.";
    cout<<"\nVery intense exercise: 2+ hours of evaluted heart rate activity.";

    //ask user to continue next calculation or not
    cout<<"\n\nDo you want to enter other data? [Y @ N]: ";
    cin>>newinput;//read the user input
    newinput=toupper(newinput);//ensure that the user input is always in capital letter
    }while(newinput=='Y');
    cout<<"\nThank you :)";//say thank you for used this program
    return 0;
}