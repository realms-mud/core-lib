//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("baddies went north", "@S@`Movement to the north!' @D@hisses "
        "Alberich as he points in that direction.");

    addTopic("donald is enthusiatic", "@D@Alberich smirks as he readies "
        "himself, @S@`Well, ain't he the enthusiastic one?' @D@With considerably "
        "less excitement, Alberich follows Donald.");

    addTopicInterjection("donald is enthusiatic",
        "/tutorial/characters/thomas/thomas.c",
        "donald is a dipshit", 1);

    addTopic("wait you ninny", "@D@Alberich grabs Donald's shoulder "
        "and harshly whispers, @S@`Half a minute, there might be others.'");

    addTopicInterjection("wait you ninny",
        "/tutorial/characters/donald/donald.c",
        "ignore and attack", 1);

    addTopic("daft bastard", "@D@Alberich looks livid as he angrily "
        "shouts, @S@`Daft bastard! Where the 'ell did you learn yer "
        "tactics, orcs?'");
    addTopicEvent("daft bastard", "followDonaldIntoTheFray");

    addTopic("good. a blissful interlude", "@D@Alberich mumbles loudly to "
        "himself, @S@`Aye! No sense getting us all killed because our "
        "commander has his head so far up... Ahh hell! We've got company!'");
    addTopicEvent("good. a blissful interlude", "fightAtTheEntrance");

    addTopic("hell with that", "@D@Alberich shakes his head vigorously and "
        "states, @S@`Hell with that! Wear it your damned self, sir!'");

    addTopicInterjection("hell with that",
        "/tutorial/characters/bregar/bregar.c",
        "that's distracting", 1);
}
