import sys
import matplotlib
import os

import matplotlib.pyplot as plt
import numpy as np


def audience_poll(a): 
    if (a==3 or a==5 or a==10 or a==13 or a==14): 
        p=np.array([35, 25, 25, 15])
        mylabels=["A","B","C", "D"]
        plt.pie(p, labels=mylabels, explode=[0.2, 0, 0, 0])
        plt.show()
        plt.savefig(sys.stdout.buffer)
        sys.stdout.flush() 
    
    elif (a==8 or a==12):
        p=np.array([25, 35, 25, 15])
        mylabels=["A","B","C", "D"]
        plt.pie(p, labels=mylabels, explode=[0, 0.2, 0, 0])
        plt.show()
        plt.savefig(sys.stdout.buffer)
        sys.stdout.flush()

    elif (a==1 or a==2 or a==9 or a==11): 
        p=np.array([25, 25, 35, 15])
        mylabels=["A","B","C", "D"]
        plt.pie(p, labels=mylabels, explode=[0, 0, 0.2, 0])
        plt.show()
        plt.savefig(sys.stdout.buffer)
        sys.stdout.flush()

    else: 
        p=np.array([25, 25, 15, 35])
        mylabels=["A","B","C","D"]
        plt.pie(p, labels=mylabels, explode=[0, 0, 0, 0.2])
        plt.show()
        plt.savefig(sys.stdout.buffer)
        sys.stdout.flush()

        
def double_dip(a): 
    price=[1000, 2000, 3000, 5000, 10000, 20000, 50000, 80000, 160000, 320000, 640000, 1250000, 2500000, 5000000, 10000000, 70000000 ]
    anskey=["D", "C", "C", "A"
    , "D", "A", "D", "D", "B","C", "A", "C", "B", "A", "A", "B"]
    A_option=["A. ","A.  ","A. ","A. Narada","A.  ", "A. USSR", "A. ", "A. ", "A.  ", "A.  ", "A. Presidents of India", "A. ", "A. ", "A. Anandiben Patel", "A. Deandra Dottin", "A. " ]
    
    B_option=["B. ","B.  ","B.   ","B. ", "B.  ", "B. ", "B. ", "B. ", "B. Jerusalem", "B. Andromeda Galaxy", "B.", "B. ", "B. Syama Prasad Mukherjee", "B.", "B. ", "B.  "]

    C_option=["C. Ranchi","C. Neelam Sanjiva Reddy","C. Sri Lanka","C. ", "C. Meera Sanyal", "C. ", "C. Makar Sankranti", "C. Khand", "C. ", "C. Dwarf planet Pluto", "C. ", "C. Sirisha Bandla", "C. C Rajagopalachari", "C. ", "C. ", "C. Jamsetjee Jejeebhoy"]
    
    D_option=["D. Agartala","D. Sumitra Mahajan","D. Argentina","D. Vishwamitra", "D. Indu Jain", "D. Japan", "D. Janmashtami", "D. Pradesh", "D. Gaza", "D.  ", "D. Prime Minister of India", "D. Mawya Sudan", "D. " , "D. Mamata Banerjee", "D. Cordel Jack", "D. Neville Wadia"]
     
    
    print(A_option[a])
    print(B_option[a])
    print(C_option[a])
    print(D_option[a])
    x= input("your response:")
    if x== " ": 
        lifelines(a)
    elif (x==anskey[a]):
        print("congratulations, you have won INR ", format(price[a]))
    else: 
        print("sorry, you have not chosen the right answer")
        os.system('CLS')


def flip_question(a): 
    print("The red sandalwood or red sanders trees, shown in the film “Pusha: The Rise”, are endemic to which region of India?")
    print("A. western ghats")
    print("B. eastern ghats")
    print("C. sundarbans")
    print("D. doaba")
    x= input("your answer(A/B/C/D):")
    if x=='C' : 
        print("congratulations, you have given correct answer.")
        print("------------------------------------------------------------------------")
    else: 
        print("sorry you have given the wrong answer.")
        os.system('CLS')


def lifelines(a): 
    
    print("choose one of the following lifelines: 1. audience poll, 2. double dip, 3. flip the question ")
    x=int(input("your response: "))
    if x==1: 
        if "audience poll" in lifeline_list:
         audience_poll(a)
         lifeline_list.remove("audience poll")
    elif x==2: 
        if "double dip" in lifeline_list:
         double_dip(a) 
         lifeline_list.remove("double dip")
    elif x==3:
        if "flip the question" in lifeline_list:
         flip_question(a) 
         lifeline_list.remove("flip the question")
    else: 
        print("either you have used this lifeline OR enter a valid number to use it.")
        

#name and introduction: 
print("congratulations, you you have won the Fastest Finger First!!🥳🥳")
name=input("please enter your name:")
print("instructions-")
print("1. To choose one of the 4 options, just enter the alphabet and then Enter.")
print("2. To get a lifeline, press the spacebar and then enter the number")
print("__________________________________________________________________________")
print("************************KAUN BANEGA CROREPATI*****************************")
print("__________________________________________________________________________")
print("contestant: "+name)
print("__________________________________________________________________________")

#question's list:
question_list= ["1. In which of these capitals cities in India will be the sunset first?","2. Who, among these, served first as Speaker of the Lok Sabha?","3. Which of these nations is entirely north of the equator?","4. According to Hindu scriptures, the veena of which rishi is called Mahati?", "5. Who was the founder-president of the FICCI Ladies Organisation and also served as the chairperson of the Times Group from 1999 to 2021?","6. Dr. Sarvepalli Radhakrishnan was the Indian ambassador to which country before becoming vice president in 1952?", "7. Which of these festivals is not celebrated in the month of January every year?", "8. Which of these words features in the name of most number of Indian states?", "9. Where is the Al-Aqsa Mosque, one of the holiest sites in Islam, located?", "10. Which of these astronomical objects is part of our solar system?", "11. Who appoints the Chief Election Commissioner of India?", "12. In July 2021, who became only the second Indian-born woman to fly to space?" ,"13. Who became the first Cabinet Minister of Industry and Supply of independent India?", "14. Which of these leaders was a recipient of a gallantry award in 1987 by a state government for saving two girls from drowning?", "15. Who was the first woman to score a century in international T20 cricket?", "16. Which of these businessmen was a French citizen by birth?"]


#options in the form of lists: 
A_option=["A. Gandhinagar","A. Manohar Joshi","A. Indonesia","A. Narada","A. Savitri Jindal", "A. USSR", "A. Pongal", "A. Garh", "A. Tel Aviv", "A. Crab Nebula", "A. Presidents of India", "A. Shawna Pandya", "A. R R Diwakar", "A. Anandiben Patel", "A. Deandra Dottin", "A. Jamsetji Tata" ]

B_option=["B. Bhopal","B. Balram Jakhar","B. Papua New Guinea","B. Parashurama", "B. Priyamvada Birla", "B. USA", "B. Lohri", "B. Pur", "B. Jerusalem", "B. Andromeda Galaxy", "B. Chief Justice of India", "B. Avani Chaturvedi", "B. Syama Prasad Mukherjee", "B. Vasundhara Raje Scindia", "B. Shanel Daley", "B. J R D Tata "]

C_option=["C. Ranchi","C. Neelam Sanjiva Reddy","C. Sri Lanka","C. Agastya", "C. Meera Sanyal", "C. China", "C. Makar Sankranti", "C. Khand", "C. Aleppo", "C. Dwarf planet Pluto", "C. Lok Sabha Speaker", "C. Sirisha Bandla", "C. C Rajagopalachari", "C. Uma Bharti", "C. Stacy-Ann King", "C. Jamsetjee Jejeebhoy"]

D_option=["D. Agartala","D. Sumitra Mahajan","D. Argentina","D. Vishwamitra", "D. Indu Jain", "D. Japan", "D. Janmashtami", "D. Pradesh", "D. Gaza", "D. Proxima Centauri", "D. Prime Minister of India", "D. Mawya Sudan", "D. Harekrushna Mahatab" , "D. Mamata Banerjee", "D. Cordel Jack", "D. Neville Wadia"]


#answer key:
anskey=["D", "C", "C", "A", "D", "A", "D", "D", "B","C", "A", "C", "B", "A", "A", "D"]
anslist=[]  #an empty list which will store the answers submitted by the player. 
lifeline_list=["audience poll", "double dip", "flip the question"]
correctans=0
total_amount=0

price=[1000, 2000, 3000, 5000, 10000, 20000, 50000, 80000, 160000, 320000, 640000, 1250000, 2500000, 5000000, 10000000, 70000000 ]
level=1
a=0
while a<len(question_list):
    
    print(question_list[a])
    print(A_option[a])
    print(B_option[a])
    print(C_option[a])
    print(D_option[a])
    response= input("Your answer: ")
    if response==" ": 
        lifelines(a)
        a=a+1
    elif response==anskey[a]: 
        print("congratulations, you have won INR", format(price[a]))
        print("----------------------------------------------------------------------------")
        correctans= correctans + 1
        a=a+1
    else: 
        print("Oops!!, your answer is wrong")
        exit() 
    anslist.append(response)
    
    if(a==3):  
        level=level+1
        print("congratulations, you have cleared the level 1. Now you have entered level 2.")
        print("----------------------------------------------------------------------------") 
    if(a==8):
        level= level+1
        print("congratualtions, you have cleared the level 2. Now you have entered level 3.")
        print("----------------------------------------------------------------------------")
    if(a==15): 
        print("1 CRORE!!!!")
        print("----------------------------------------------------------------------------")
    if(a==16):
        print("You have got all the questions right!!hurray!!")
        print("you are the new CROREPATI!!!!!")

