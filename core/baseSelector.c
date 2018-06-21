//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
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
protected int NumColumns = 1;
protected int HasDescription = 1;
protected int SuppressColon = 0;
protected string Type = "Character creation";

private string *UndoLog = ({ });

protected nosave string Cyan = "[0;36m%s[0m";
protected nosave string BoldWhite = "[0;37;1m%s[0m";
protected nosave string Red = "[0;31;1m%s[0m";
protected nosave string Green = "[0;32m%s[0m";
protected nosave string BoldGreen = "[0;32;1m%s[0m";

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    registerEventHandler("onSelectorCompleted");
    registerEventHandler("onSelectorAborted");
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
protected string padSelectionDisplay(string selection)
{
    string ret = "";
    if ((sizeof(Data) > 9) && (member(({ "1", "2", "3", "4", "5", "6",
        "7", "8", "9" }), selection) > -1))
    {
        ret = " ";
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected string choiceFormatter(string choice)
{
    return sprintf("%s[%s]%s - %s%s",
        (NumColumns < 3) ? "\t" : "", Red,
        padSelectionDisplay(choice), "[0;32m%-20s[0m",
        displayDetails(choice));
}

/////////////////////////////////////////////////////////////////////////////
public nomask string displayMessage()
{
    string ret = "";
    
    if(Data && sizeof(Data))
    {
        ret = sprintf(Cyan + BoldWhite + "%s", 
            sprintf("%s - ", Type), Description,
            (!SuppressColon ? ":\n" : "\n"));

        string *choices = sort_array(m_indices(Data), "sortMethod");

        int i = 1;
        foreach(string choice in choices)
        {
            string format = choiceFormatter(choice);

            ret += sprintf(format, choice, Data[choice]["name"]);
            if (!(i % NumColumns))
            {
                ret += "\n";
            }
            i++;
        }

        if (ret[sizeof(ret) - 1] != '\n')
        {
            ret += "\n";
        }
        ret += sprintf(BoldGreen, sprintf("You must select a number from 1 to %d.%s\n", sizeof(choices), AllowUndo ? " You may also undo or reset." : ""));
        if (AllowAbort)
        {
            ret += sprintf(Green, "Type 'exit' if you do not wish to make a selection at this time.\n");
        }
        if (HasDescription)
        {
            ret += sprintf(Green, "For details on a given choice, type 'describe X' (or '? X') where\nX is the option about which you would like further details.\n");
        }
        ret += sprintf(BoldGreen, additionalInstructions());
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
protected int suppressMenuDisplay()
{
    return 0;
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
        else if (!suppressMenuDisplay())
        {
            tell_object(User, displayMessage());
        }
    }
    else
    {
        UndoLog += ({ selection });

        if (!suppressMenuDisplay())
        {
            tell_object(User, displayMessage());
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
protected int handleSpecialSelection()
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int applySelection(string arguments)
{
    int ret = 0;
    if(User && Data)
    {
        ret = Block;

        string element;
        if(((sscanf(arguments, "describe %s", element) == 1) ||
            (sscanf(arguments, "? %s", element) == 1)) &&
            member(Data, element) && HasDescription)
        {
            ret = Describe;
            tell_object(User, displayMessage() + "\n");
            tell_object(User, sprintf(Cyan, Data[element]["description"]));
        }
        else if (handleSpecialSelection())
        {
            makeSelection(arguments);
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
        else if ((arguments == "exit") && AllowAbort)
        {
            ret = Success;
            tell_object(User, sprintf(Cyan, Type + " has been exited.\n"));
            notify("onSelectorAborted");
        }
        else if(member(Data, arguments))
        {
            ret = Success;
            string choice = Data[arguments]["name"];
            if (sizeof(choice) > 48)
            {
                choice = choice[0..48] + "...";
            }
            tell_object(User, sprintf(Cyan, sprintf("You have selected '%s'.\n",
                choice)));

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
protected void setUpUserForSelection()
{
}

/////////////////////////////////////////////////////////////////////////////
public nomask varargs void initiateSelector(object user, int alreadyInitialized)
{
    User = user;

    if (!alreadyInitialized)
    {
        setUpUserForSelection();
    }
    else
    {
        AllowAbort = 1;
    }
    tell_object(User, displayMessage());
}

/////////////////////////////////////////////////////////////////////////////
public void onSelectorAborted(object caller)
{
    caller->cleanUp();
    notify("onSelectorAborted");
}
