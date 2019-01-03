//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("you heard the man", "\n@D@Donald nods and looks at Halgaladh, "
        "@S@`Well you heard the man! Get yer arse moving!' @D@He nods "
        "at ##InitiatorName## and adds, @S@`Move out! Alberich, you're on "
        "point.'");
}
