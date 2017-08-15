//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/events.c";

#define Block 1
#define Describe 2
#define Success 3

protected object User = 0;
protected mapping Data = 0;
protected string Description = 0;
protected int AllowUndo = 1;
protected int AllowAbort = 0;

private string *UndoLog = ({ });

private nosave string Cyan = "[0;36m%s[0m";
private nosave string BoldWhite = "[0;37;1m%s[0m";
private nosave string Red = "[0;31m%s[0m";
private nosave string Green = "[0;32m%s[0m";
private nosave string BoldGreen = "[0;32;1m%s[0m";

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    registerEventHandler("onSelectorCompleted");

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

        ret += sprintf(BoldGreen, sprintf("You must select a number from 1 to %d.%s\n", sizeof(choices), AllowUndo ? " You may also undo or reset." : ""));
        ret += sprintf(Green, "For details on a given choice, type 'describe X' where\nX is the option about which you would like further details.\n");
        if (AllowAbort)
        {
            ret += sprintf(Green, "Type 'abort' if you do not wish to make a selection at this time.\n");
        }
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
            notify("onSelectorCompleted");
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
        else if ((arguments == "undo") && sizeof(UndoLog) && AllowUndo)
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
        else if ((arguments == "reset") && sizeof(UndoLog) && AllowUndo)
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
        else if ((arguments == "abort") && AllowAbort)
        {
            ret = Success;
            notify("onSelectorCompleted");
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
public nomask varargs void initiateSelector(object user, int alreadyInitialized)
{
    User = user;

    if (!alreadyInitialized)
    {
        setUpUserForSelection(User);
    }
    else
    {
        AllowAbort = 1;
    }
    tell_object(User, displayMessage());
}