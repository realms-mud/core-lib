//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#define Block 1
#define Describe 2
#define Success 3

protected object User = 0;
protected mapping Data = 0;
protected string Description = 0;

private string *UndoLog = ({ });

private nosave string Cyan = "[0;36m%s[0m";
private nosave string BoldWhite = "[0;37;1m%s[0m";
private nosave string Red = "[0;31m%s[0m";
private nosave string Green = "[0;32m%s[0m";
private nosave string BoldGreen = "[0;32;1m%s[0m";

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    add_action("applySelection", "", 3);
}

/////////////////////////////////////////////////////////////////////////////
public nomask void cleanUp()
{
    destruct(this_object());
}

/////////////////////////////////////////////////////////////////////////////
public nomask int sortMethod(string a, string b)
{
    return to_int(a) > to_int(b);
}

/////////////////////////////////////////////////////////////////////////////
protected string additionalInstructions()
{
    return "";
}

/////////////////////////////////////////////////////////////////////////////
protected string displayDetails(string choice)
{
    return "";
}

/////////////////////////////////////////////////////////////////////////////
public nomask string displayMessage()
{
    string ret = "";
    
    if(Data)
    {
        ret = sprintf(Cyan + BoldWhite + ":\n", "Character creation - ",
            Description);

        string *choices = sort_array(m_indices(Data), "sortMethod");
        foreach(string choice in choices)
        {
            string format = sprintf("\t[%s] - %s%s\n", Red, "[0;32m%-20s[0m",
                displayDetails(choice));
            ret += sprintf(format, choice, Data[choice]["name"]);
        }

        ret += sprintf(BoldGreen, sprintf("You must select a number from 1 to %d. You may also undo or reset.\n", sizeof(choices)));
        ret += sprintf(Green, "For details on a given choice, type 'describe X' where\nX is the option about which you would like further details.\n");
        ret += sprintf(BoldGreen, additionalInstructions());
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected int processSelection(string selection)
{
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
protected void undoSelection(string selection)
{
}

/////////////////////////////////////////////////////////////////////////////
private nomask void makeSelection(string selection)
{
    int finished = processSelection(selection);
    if (finished)
    {
        if (finished == 1)
        {
            remove_action(1, User);
            User = 0;
            Data = 0;
            call_out("cleanUp", 1);
        }
        else
        {
            tell_object(User, displayMessage());
        }
    }
    else
    {
        UndoLog += ({ selection });
        tell_object(User, displayMessage());
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask int applySelection(string arguments)
{
    int ret = 0;
    if(User && Data)
    {
        ret = Block;

        string element;
        if((sscanf(arguments, "describe %s", element) == 1) &&
            member(Data, element))
        {
            ret = Describe;
            tell_object(User, sprintf(Cyan, Data[element]["description"]));
        }
        else if ((arguments == "undo") && sizeof(UndoLog))
        {
            ret = Success;
            undoSelection(UndoLog[sizeof(UndoLog) - 1]);

            tell_object(User, sprintf(Cyan,
                "You have reverted your previous selection.\n") +
                displayMessage());
            
            if (sizeof(UndoLog) > 1)
            {
                UndoLog = UndoLog[0..(sizeof(UndoLog) - 2)];
            }
            else
            {
                UndoLog = ({ });
            }
        }
        else if ((arguments == "reset") && sizeof(UndoLog))
        {
            ret = Success;
            foreach(string selection in UndoLog)
            {
                undoSelection(selection);
            }
            tell_object(User, sprintf(Cyan,
                "You have reset your selections.\n") + displayMessage());

            UndoLog = ({});
        }
        else if(member(Data, arguments))
        {
            ret = Success;
            tell_object(User, sprintf(Cyan, sprintf("You have selected '%s'.\n",
                Data[arguments]["name"])));

            makeSelection(arguments);
        }
        else
        {
            tell_object(User, displayMessage());
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected void setUpUserForSelection(object user)
{
}

/////////////////////////////////////////////////////////////////////////////
public nomask void initiateSelector(object user)
{
    User = user;
    setUpUserForSelection(User);
    tell_object(User, displayMessage());
}