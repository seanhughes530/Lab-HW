#!/usr/bin/env python

import feedparser
import time

import subprocess
import smtplib
import socket
import time
from email.mime.text import MIMEText
import datetime
import urllib2

user='hughs178@newschool.edu'
passwd='*******'


while True:
    newmails = feedparser.parse("https://"+user+":"+passwd+"@mail.google.com/$

    def sumLength(n):
        if n > 90:
            print "That's long"
        else:
            print "That's not too long"

    for i in newmails:
        if str(i.title).startswith("Your"):
            a = str(i.summary)
            b = len(a)
            sumLength(b)


    to = 'hughs178@newschool.edu'
    gmail_user = 'hughs178@newschool.edu'
    gmail_password = '*********'
    smtpserver = smtplib.SMTP('smtp.gmail.com', 587)
    smtpserver.ehlo()
    smtpserver.starttls()
    smtpserver.ehlo
    smtpserver.login(gmail_user, gmail_password)
    today = datetime.date.today()

    msg = (sumLength(b))
    msg['Subject'] = 'Homework'
    msg['From'] = gmail_user
    msg['To'] = to
    smtpserver.sendmail(gmail_user, [to], msg.as_string())
    smtpserver.quit()

    time.sleep(60)

    #didn't get it to work just yet. Got one email sent but there was no content.
    #Now getting error's about the 'Subject'
