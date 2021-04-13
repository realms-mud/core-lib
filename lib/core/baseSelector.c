//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
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
protected object configuration = load_object("/lib/dictionaries/configurationDictionary.c");
protected string colorConfiguration = "none";
protected object CompletionHandler;
protected string CompletionEvent;

private string *UndoLog = ({ });

/////////////////////////////////////////////////////////////////////////////
public void InitializeSelector()
{

}

/////////////////////////////////////////////////////////////////////////////
public void create()
{
    InitializeSelector();
}

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
        (NumColumns < 3) ? "    " : "",
        configuration->decorate("%s", "number", "selector", colorConfiguration),
        padSelectionDisplay(choice),
        configuration->decorate("%-20s", "choice enabled", "selector", colorConfiguration),
        displayDetails(choice));
}

/////////////////////////////////////////////////////////////////////////////
public nomask string displayMessage()
{
    string ret = "";
    
    if(Data && sizeof(Data))
    {
        ret = sprintf(
            configuration->decorate("%s", "title", "selector", colorConfiguration) + 
            configuration->decorate("%s", "menu name", "selector", colorConfiguration) +
            "%s",
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
        ret += configuration->decorate(sprintf("You must select a number from "
            "1 to %d.%s\n", sizeof(choices), AllowUndo ? " You may also undo "
            "or reset." : ""), "instructions", "selector", colorConfiguration);
        if (AllowAbort)
        {
            ret += configuration->decorate("Type 'exit' if you do not wish "
                "to make a selection at this time.\n", "details", "selector", 
                colorConfiguration);
        }
        if (HasDescription)
        {
            ret += configuration->decorate("For details on a given "
                "choice, type 'describe X' (or '? X') where\nX is the option "
                "about which you would like further details.\n", 
                "details", "selector", colorConfiguration); 
        }

        ret += configuration->decorate(additionalInstructions(), "instructions",
            "selector", colorConfiguration);
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
public void registerCompletionEvent(object handler, string event)
{
    CompletionHandler = handler;
    CompletionEvent = event;
}

/////////////////////////////////////////////////////////////////////////////
public void emitCompletionEvent()
{
    if (objectp(CompletionHandler) && stringp(CompletionEvent))
    {
        CompletionHandler->notify(CompletionEvent);
    }
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
            emitCompletionEvent();
            notifySynchronous("onSelectorCompleted");
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

            tell_object(User, configuration->decorate(
                member(Data[element],"do not format") ? Data[element]["description"] :
                format(Data[element]["description"], 78),
                "description", "selector", colorConfiguration));
        }
        else if (handleSpecialSelection())
        {
            makeSelection(arguments);
        }
        else if ((arguments == "undo") && sizeof(UndoLog) && AllowUndo)
        {
            ret = Success;
            undoSelection(UndoLog[sizeof(UndoLog) - 1]);

            tell_object(User, configuration->decorate(
                "You have reverted your previous selection.\n",
                "action", "selector", colorConfiguration) +
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

            tell_object(User, configuration->decorate(
                "You have reset your selections.\n",
                "action", "selector", colorConfiguration) +
                displayMessage());

            UndoLog = ({});
        }
        else if ((arguments == "exit") && AllowAbort)
        {
            ret = Success;

            tell_object(User, configuration->decorate(
                Type + " has been exited.\n",
                "action", "selector", colorConfiguration));

            emitCompletionEvent();
            notifySynchronous("onSelectorAborted");
        }
        else if(member(Data, arguments))
        {
            ret = Success;
            string choice = Data[arguments]["name"];
            if (sizeof(choice) > 48)
            {
                choice = choice[0..48] + "...";
            }

            tell_object(User, configuration->decorate(
                sprintf("You have selected '%s'.\n", choice),
                "action", "selector", colorConfiguration)); 

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
    colorConfiguration = User->colorConfiguration();

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
    emitCompletionEvent();
    notifySynchronous("onSelectorAborted");
}
