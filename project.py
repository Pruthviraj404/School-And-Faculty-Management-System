#Creating a simple GUI registration form using Tkinter in Python  
#import the tkinter module into our code  
from tkinter import *  
from tkinter import messagebox
from tkinter import *
from tkinter import ttk
import customtkinter  # <- import the CustomTkinter module
from CTkMessagebox import CTkMessagebox
import tkinter as tk

import customtkinter as ctk

f = ('Helvetica', 14)
def submitaction():
    fname = entry1.get()
    lname = entry2.get()

    if not fname or not lname:
         messagebox=CTkMessagebox(title="Error", message="No Form Filled!!!", icon="cancel")
         messagebox.wait_window()
         
    elif fname.isspace() or lname.isspace():
         messagebox=CTkMessagebox(title="Error", message="No Form Filled!!!", icon="cancel")
         messagebox.wait_window()
    else:
         messagebox=CTkMessagebox(message="Data is successfully submitted.",icon="check", option_1="Ok")
         messagebox.wait_window()
     
    

        
        
#Creating the object 'base' of the Tk()  
base = customtkinter.CTk()  
base.geometry('1200x990')
# base.configure(background='grey')


entry1 = customtkinter.CTkEntry(master=base,
                               placeholder_text="FIRST NAME",
                               width=300,
                               height=50,
                               border_color='#FFFFFF',
                               border_width=2,
                            
                               corner_radius=10)
entry1.place(x=10,y=10)



entry2 = customtkinter.CTkEntry(master=base,
                               placeholder_text="LAST NAME",
                               width=300,
                               height=50,
                               border_color='#FFFFFF',
                               border_width=2,
                            
                               corner_radius=10)
entry2.place(x=10,y=100)


entry3 = customtkinter.CTkEntry(master=base,
                               placeholder_text="EMAIL",
                               width=300,
                               height=50,
                               border_color='#FFFFFF',
                               border_width=2,
                               corner_radius=10)
entry3.place(x=10,y=200)


checkbox1 = customtkinter.CTkCheckBox(master=base, text="Male", onvalue="on", offvalue="off")
checkbox1.place(x=15,y=280)
checkbox2 = customtkinter.CTkCheckBox(master=base, text="Female", onvalue="on", offvalue="off")
checkbox2.place(x=140,y=280)
combobox = customtkinter.CTkComboBox(master=base, border_color='#00ff00', justify='center',
                                     values=["First Year", "Second Year"])
combobox.set('Academic Year')
combobox.place(x=15, y=350)


# ttk.Separator(
#     base,
#     takefocus=0,
#     orient=VERTICAL
# ).place(x=350, y=0, relheight=1)





b1 = customtkinter.CTkButton(master=base,
                                 hover_color='#8a3772',
                                 text_color='#000000',
                                 width=200,
                                 height=40,
                                 border_color='#f8f7fa',
                                 border_width=3,
                                 corner_radius=10,
                                 text="Submit",
                                 command=submitaction
                              )         

b1.place(x=20,y=500)
# button.place(x=670,y=270
# b1=customtkinter.CTkButton(base, text="Check CTkMessagebox", command=submitaction)

# ttk.Separator(
#     base,
#     takefocus=0,
#     orient=VERTICAL
# ).place(x=350, y=0, relheight=1)
  
#Calling the mainloop method to execute the entire program.  

base.mainloop()  