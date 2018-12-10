//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("berenar interjects", "@S@`@C@##ActorSubjective##'s already dead. "
        "##ActorPossessive## body just hasn't figured "
        "it out yet.', @D@interjects Berenar as he impassively stares at you. He "
        "looks rather beaten up, but is still hale. He is rather rattled and with "
        "a broken sigh, he adds @S@`By the gods, Galadhel, I can't find the words "
        "to even describe what I've seen. Those who were dead animated? Their "
        "blades as fell as ever... Those robed cowards... they're alive. At least "
        "most are. Basil shot one through the throat a few minutes ere you got "
        "here. At least a dozen of those... things... fell to the ground after "
        "that... That got their attention... got Basil killed too. One of the "
        "black-robed ones raised his hand, there was a flash... metal, perhaps, "
        "and something struck Basil - sliced his neck wide open. Still, it was "
        "enough to cause them to flee. Looks like they dragged their fallen "
        "with 'em though.'");

    addResponse("berenar interjects", "\x1b[0;31m[Say nothing...]\x1b[0m", "@D@You remain silent.");
    addTopic("player will live", "@S@`I may have spoken out of turn. ##ActorName## "
        "has regained consciousness and does not yet look ready to depart us.' @D@"
        "notes Berenar as he crouches down to help Galadhel tend to your wounds.");
    addResponseTopic("berenar interjects", "\x1b[0;31m[Say nothing...]\x1b[0m", "player will live");
    addTopicEvent("player will live", "playerAgainLosesConsciousness");

    addResponse("berenar interjects", "I'm not dead yet...",
        "@D@You raise your head up slightly and say, `@S@The rumor of my demise is greatly exaggerated. I hurt... everywhere, "
        "but you'll not be rid of me so easily.'");
    addTopic("not dead", "@S@`You have my apologies, ##ActorName##. Nay, stay down "
        "and let me tend to you. I marvel that you are alive at all...' @D@says "
        "Berenar and he crouches down to help Galadhel tend your wounds.");
    addResponseTopic("berenar interjects", "I'm not dead yet...", "not dead");
    addTopicEvent("not dead", "playerAgainLosesConsciousness");
}
