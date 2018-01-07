//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("save the dead", "Way to go! you saved the king!");
    addRepeatableTopic("king is dead", "Piss off you gorbellied twit-goblin! The king is dead because of you.");
}
