DSA Friends Recommendation Project 

Team 55

International Institute of Information Technology Hyderabad

---------------------------------------------------------------------------------------------------------------------------------------
MOTIVATION

We are fascinated about how Facebook manages to recommend friends which are in most of the cases related to us in some ways.

So we decided to come up with own system to recommend friends.

---------------------------------------------------------------------------------------------------------------------------------------
ABOUT

The project is on Friends Recommendation system.

A system which manages our friends. The system keeps record of the people we wish to follow and people who wish to follow us along with the details(like age , city , organization).

This system is a bit different from the facebook. In this system a person A may follow person B but person B need not follow person A.  

A new user can register and delete his/her account very easily. Each user has his/her unique UserID.

The system recommends friends to you(makes it easier to search friends).

---------------------------------------------------------------------------------------------------------------------------------------
PROGRAMMING LANGUAGE

The whole code has been written using basic C language. The core concepts used in the project are HASHTABLES , AVL TREES AND GRAPH THEORY.

---------------------------------------------------------------------------------------------------------------------------------------
HOW DOES THE SYSTEM WORK?

When the user registers in the system the user will have to fill the following details:
    
    NAME
    
    AGE
    
    CITY
    
    ORGANIZATION(May be School/University/Profession etc)

The user will be given a USERID(It will be unique). The USERID given will be the least of the available USERIDs.

When the user registers he/she will be given 10 friend recommendations. The recommendation will be on the basis of most number of    common parameters. The more parameters a user has in common, the more preferred it will be.

For an already registered user the recommendations are given on the basis of second friends(friends of friends) , third friends etc.
The order of preference is: second friends > third friends > fourth friends and so on.

The user can unregister from the system just by using his/her USERID. After unregistration the USERID can be used again.

Also the you can visit the details of any user using the USERID.

---------------------------------------------------------------------------------------------------------------------------------------

INSTRUCTIONS ON COMPILATION

You are just required to compile the file Menu.c and then run the program.

----------------------------------------------------------------------------------------------------------------------------------------
HOW TO RUN TEST CASES?

When you run the program, an interface will open. All the details and steps will be there in the interface.

When the MENU opens:
   
Five options will be available:-
   
Choose the option number for performing a specific function.
   
   1. Add New User 
      
      Option: 1
      
      Inputs required = Name , Age , Organization , City
   
   2. Get Details of a User from USERID 
      
      Option: 2
      
      Inputs required = USERID of the user
  
   3. Make Friends 
     
      Option: 3
     
      Inputs required = USERIDs of two users(The one who is following and one who is being followed)
  
   4. Show Friends of a User
     
      Option: 4
    
      Inputs required = USERID of the user
   
   5. Show Friend Recommendation for a User 
      
      Option: 5
      
      Inputs required = USERID for the User whose recommendations are to be found , Number of recommendations
   
   6. Unregister a user
      
      Option: 6
      
      Inputs required = USERID of the User
   
   7. Check Friendship status
      
      Option: 7
      
      Inputs required = USERIDs of both the Users 
   
   8. Exit
      
      Option: 8
   
-------------------------------------------
TEAM MEMBERS

KEYUR GANESH CHAUDHARY

HARSHAVARDHAN THATIPAMULA

MUDHIREDDY NANDINI REDDY

ROHIT REDDY LINGALA

YALAKA SURYA TEJA REDDY

-------------------------------------------







