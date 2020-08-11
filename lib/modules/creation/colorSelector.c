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
        Description = "Choose your color configuration";
        AllowUndo = 0;

        Data = ([
            "1":([
                "name":"No color support",
                "description" : "This option sends the user's client only "
                    "simple text without ASNI colors via escape characters. "
                    "It is useful if your client does not support colors or "
                    "you are using a screen reader.\n",
                "value": "none"
            ]),
            "2":([
                "name":"3-bit (8 colors)",
                "description" : "This option sends the user's client text "
                    "with basic ASNI color support for eight colors. Early "
                    "clients often only supported these colors. \x1b[0;32mIf "
                    "your client supports this, you should see this message "
                    "in green.\x1b[0m\n",
                "value": "3-bit",
            ]),
            "3":([
                "name":"8-bit (256 colors)",
                "description" : "This option sends the user's client text "
                    "with basic ASNI color support for 256 colors. Many "
                    "modern clients support these colors. \x1b[0;38;5;30mIf "
                    "your client supports this, you should see this message "
                    "in turquoise.\x1b[0m\n",
                "value": "8-bit",
            ]),
            "4":([
                "name":"24-bit (true color)",
                "description" : "This option sends the user's client text "
                    "with basic ASNI color support for 16,777,216 colors. Some "
                    "modern clients support these colors, but many do not. "
                    "\x1b[0;38;2;0;95;135mIf your client supports this, you "
                    "should see this message in blue-green.\x1b[0m\n",
                "value": "24-bit",
            ]),
            "5":([
                "name":"grayscale (26 colors)",
                "description" : "This option sends the user's client text "
                    "with basic ASNI color support for 26 grayscale colors. Some "
                    "modern clients support these colors, but many do not. "
                    "\x1b[0;38;5;238mIf your client supports this, you "
                    "should see this message in blue-green.\x1b[0m\n",
                "value": "grayscale",
            ]),
        ]);
    }
}

/////////////////////////////////////////////////////////////////////////////
protected nomask int processSelection(string selection)
{
    User->colorConfiguration(Data[selection]["value"]);
    return 1;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask string additionalInstructions()
{
    return "You can change this value after character creation "
        "using the 'set' command.\n";
}
