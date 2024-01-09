//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/events.c"; 

#define Block 1
#define Describe 2
#define Success 3

private object User = 0;
private mapping Data = 0;
private string ResearchTitle = 0;
private object configuration = getDictionary("configuration");
private string colorConfiguration = "none";
private object Parent = 0;

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    add_action("applyResearchChoice", "", 3);
}

/////////////////////////////////////////////////////////////////////////////
public void cleanUp()
{
    destruct(this_object());
}

/////////////////////////////////////////////////////////////////////////////
public void setResearchTitle(string title, object parent)
{
    if(stringp(title))
    {
        ResearchTitle = title;
    }
    Parent = parent;
}

/////////////////////////////////////////////////////////////////////////////
private string padSelectionDisplay(string selection)
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
public string displayMessage()
{
    string ret = "";
    
    if(Data)
    {
        ret = configuration->decorate("A new research choice is available: ",
                "title", "selector", colorConfiguration) +
            configuration->decorate(Data["1"]["choice"] + "\n",
                "menu name", "selector", colorConfiguration);

        string *choices = sort_array(m_indices(Data), (: $1 > $2 :));
        foreach(string choice in choices)
        {
            ret += sprintf("    [%s]%s - %s\n",
                configuration->decorate(choice, "number", "selector", colorConfiguration),
                padSelectionDisplay(choice),
                configuration->decorate(Data[choice]["name"],
                    "choice enabled", "selector", colorConfiguration));
        }

        ret += configuration->decorate(sprintf("You must select a number from "
            "1 to %d.\n", sizeof(choices)), 
            "instructions", "selector", colorConfiguration);

        ret += configuration->decorate("For details on a given "
            "choice, type 'describe X' (or '? X') where\nX is the option "
            "about which you would like further details.\n",
            "details", "selector", colorConfiguration);
        }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
private void makeSelection(string selection)
{
    switch(Data[selection]["type"])
    {
        case "research object":
        {
            User->selectResearchChoice(Data[selection]["key"],
                Data[selection]["choice"], selection);
            break;
        }
        case "research tree":
        {
            User->selectResearchPath(Data[selection]["key"],
                Data[selection]["choice"], selection);
            break;
        }
    }

    remove_action(1, User);
    User = 0;
    Data = 0;
    ResearchTitle = 0;

    if (objectp(Parent))
    {
        Parent->onSelectorCompleted(this_object());
    }
    else
    {
        notifySynchronous("onSelectorCompleted");
        call_out("cleanUp", 1);
    }
}

/////////////////////////////////////////////////////////////////////////////
public void onResearchChoiceAvailable(object user, mapping data)
{
    if(ResearchTitle && user && objectp(user) && data && mappingp(data) &&
        member(data, "1") && member(data["1"], "choice") &&
        member(data["1"], "type") && (ResearchTitle == data["1"]["choice"]))
    {
        User = user;
        Data = data;
        colorConfiguration = User->colorConfiguration();
        User->unregisterEvent(this_object());

        if(sizeof(data) == 1)
        {
            makeSelection("1");
        }
        else
        { 
            tell_object(User, displayMessage());
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
public int applyResearchChoice(string arguments)
{
    int ret = 0;
    if(User && Data)
    {
        ret = Block;

        string element;
        if(((sscanf(arguments, "describe %s", element) == 1) ||
            (sscanf(arguments, "? %s", element) == 1)) &&
            member(Data, element))
        {
            ret = Describe;
            tell_object(User, sprintf(Data[element]["description"]));
        }
        else if(member(Data, arguments))
        {
            ret = Success;
            tell_object(User, configuration->decorate(
                sprintf("You have selected '%s'.\n", Data[arguments]["name"])));

            makeSelection(arguments);
        }
        else
        {
            tell_object(User, displayMessage());
        }
    }
    return ret;
}
