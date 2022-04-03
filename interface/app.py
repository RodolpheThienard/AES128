from tkinter import *

# Configuration
window = Tk()
window.title("AES")
window.geometry("500x300")
window.minsize(200, 200)
window.config(background="#41B77F")

frame = Frame(window, bg="#41B77F")

label_title = Label(frame, text="Clé pour encrypter/decrypter", font=("Arial", 20), bg="#41B77F", fg='white')
# label_title.grid(row=0, column=0, sticky=W)
label_title.pack()

frame.pack(expand=YES)

# input string box
var_entry = StringVar()
entry = Entry(window, textvariable=var_entry)
entry.pack()

#Button crypt which call C code
crypt_button = Button(window, text="crypt")
crypt_button.pack()


# Main loop
window.mainloop()