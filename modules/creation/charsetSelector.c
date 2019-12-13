//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/core/baseSelector.c";

/////////////////////////////////////////////////////////////////////////////
public nomask void reset(int arg)
{
    if (!arg)
    {
        Description = "Choose your character set configuration";
        AllowUndo = 0;

        Data = ([
            "1":([
                "name":"ASCII-only",
                "description" : "This option sends the user's client only "
                    "simple 7-bit ASCII text. It is useful if your client "
                    "does not support unicode or you are using a screen "
                    "reader.\n",
                "value": "ascii"
            ]),
            "2":([
                "name":"Unicode",
                "description" : "This option sends the user's client text "
                    "with unicode support. Early clients often do not "
                    "support these characters. If your client supports "
                    "this, you should see a skull and crossbones here -> "
                    "\xe2\x98\xa0\n",
                "value": "unicode",
            ]),
        ]);
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    User->charsetConfiguration(Data[selection]["value"]);
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string additionalInstructions()
{
    return "You can change this value after character creation "
        "using the 'set' command.\n";
}
