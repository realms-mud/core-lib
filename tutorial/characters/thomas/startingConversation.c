//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("get moving", "@S@`Our illustrious commander said...' "
        "@D@Thomas clears his throat and does his best immitation of Donald, "
        "@S@``Get that stupid shit ##ActorName## back here! We have enemies "
        "at hand!' Seriously, ##ActorName##.... what the hell are you doing?' "
        "@D@Without waiting for a response, Thomas runs off.");

    addTopic("donald is a dipshit", "@S@`Enthusiastic?' @D@Thomas mutters "
        "grimly. @S@`That dipshit is rushing headlong into a trap. Bah. "
        "Nothing for it but to join him, yes?'");

    addTopic("yeah no thanks", "@S@`To what end? You bloodied the damned "
        "things enough that they won't be of much use.' @D@Thomas looks at the "
        "remains of the one Donald decapitated and wryly adds, @S@`Oh well, "
        "Alberich can wear that one.' @D@he says this last with a gesture "
        "to the blood-soaked cloth.");

    addTopicInterjection("yeah no thanks",
        "/lib/tutorial/characters/alberich/alberich.c",
        "hell with that", 1);
}
