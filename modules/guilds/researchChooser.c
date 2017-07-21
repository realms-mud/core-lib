//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#define Block 1
#define Describe 2
#define Success 3

private object User = 0;
private mapping Data = 0;
private string ResearchTitle = 0;

private nosave string Cyan = "[0;36m%s[0m";
private nosave string BoldWhite = "[0;37;1m%s[0m";
private nosave string Red = "[0;31m%s[0m";
private nosave string Green = "[0;32m%s[0m";
private nosave string BoldGreen = "[0;32;1m%s[0m";

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
public void setResearchTitle(string title)
{
    if(stringp(title))
    {
        ResearchTitle = title;
    }
}

/////////////////////////////////////////////////////////////////////////////
public int sortMethod(string a, string b)
{
    return to_int(a) > to_int(b);
}

/////////////////////////////////////////////////////////////////////////////
public string displayMessage()
{
    string ret = "";
    
    if(Data)
    {
        ret = sprintf(Cyan + BoldWhite + "\n", "A new research choice is available: ",
            Data["1"]["choice"]);

        string *choices = sort_array(m_indices(Data), "sortMethod");
        foreach(string choice in choices)
        {
            string format = sprintf("\t[%s] - %s\n", Red, Green);
            ret += sprintf(format, choice, Data[choice]["name"]);
        }

        ret += sprintf(BoldGreen, sprintf("You must select a number from 1 to %d.\n", sizeof(choices)));
        ret += sprintf(Green, "For details on a given choice, type 'describe X' where\nX is the option about which you would like further details.\n");
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
                Data[selection]["choice"]);
            break;
        }
        case "research tree":
        {
            User->selectResearchPath(Data[selection]["key"],
                Data[selection]["choice"]);
            break;
        }
    }

    remove_action(1, User);
    User = 0;
    Data = 0;
    ResearchTitle = 0;
    call_out("cleanUp", 1);
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

        User->unregisterEvent(this_object());

        if(sizeof(data) == 1)
        {
            makeSelection("1");
        }
        else
        { 
            write(displayMessage());
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
        if((sscanf(arguments, "describe %s", element) == 1) &&
            member(Data, element))
        {
            ret = Describe;
            printf(Data[element]["description"]);
        }
        else if(member(Data, arguments))
        {
            ret = Success;
            printf(Cyan, sprintf("You have selected '%s'.\n", 
                Data[arguments]["name"]));

            makeSelection(arguments);
        }
        else
        {
            write(displayMessage());
        }
    }
    return ret;
}
