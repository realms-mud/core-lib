//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

private object Book;

/////////////////////////////////////////////////////////////////////////////
public nomask void setBook(object book)
{
    Book = book;
}

/////////////////////////////////////////////////////////////////////////////
public nomask void InitializeSelector()
{
    AllowUndo = 0;
    AllowAbort = 1;
    HasDescription = 0;
    NumColumns = 2;
    Type = "";
    Data = ([]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void setUpUserForSelection()
{
    if (!Book)
    {
        raise_error("ERROR: bookSelector.c - The book has not been set.\n");
    }

    string title = Book->query("title");
    if (!title)
    {
        title = Book->query("name");
    }
    if (!title)
    {
        title = "Untitled";
    }

    Type = title;
    Description = "Select a chapter to read";
    SuppressColon = 1;

    mapping *chapters = Book->query("chapters");
    if (chapters && sizeof(chapters))
    {
        for (int i = 0; i < sizeof(chapters); i++)
        {
            string key = to_string(i + 1);
            Data[key] = ([
                "name": chapters[i]["title"],
                "type": "chapter",
                "description": chapters[i]["text"],
                "do not format": 1,
            ]);
        }
    }

    string exitKey = to_string(sizeof(Data) + 1);
    Data[exitKey] = ([
        "name": "Close book",
        "type": "exit",
        "description": "Stop reading and close the book.\n"
    ]);
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    if (User && member(Data, selection))
    {
        if (Data[selection]["type"] == "exit")
        {
            return 1;
        }

        if (Data[selection]["type"] == "chapter")
        {
            tell_object(User, configuration->decorate(
                sprintf("\n  %s\n\n", Data[selection]["name"]),
                "heading", "selector", colorConfiguration) +
            configuration->decorate(
            format(Data[selection]["description"], 78) + "\n",
            "description", "selector", colorConfiguration));

            Data = (["1": ([
                "name": "Return",
                "type": "return",
                "description": "Return to the table of contents.\n"
            ])]);

            return -1;
        }

        if (Data[selection]["type"] == "return")
        {
            setUpUserForSelection();
            return -1;
        }
    }
    return -1;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string selection()
{
    return "read";
}
