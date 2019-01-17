//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("berenar interjects", "\n@S@`@C@##ActorSubjective##'s already dead. "
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

    addResponse("berenar interjects", "@I@Say nothing...@E@", "@D@You remain silent.");
    addTopic("player will live", "@S@`I may have spoken out of turn. ##ActorName## "
        "has regained consciousness and does not yet look ready to depart us.' @D@"
        "notes Berenar as he crouches down to help Galadhel tend to ##InitiatorPossessive## wounds.");
    addResponseTopic("berenar interjects", "@I@Say nothing...@E@", "player will live");
    addTopicEvent("player will live", "playerAgainLosesConsciousness");

    addResponse("berenar interjects", "I'm not dead yet...",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::raise## ##InitiatorPossessive## "
        " head up slightly and ##ResponseInfinitive::say##, `@S@The rumor of my "
        "demise is greatly exaggerated. I hurt... everywhere, "
        "but you'll not be rid of me so easily.'");
    addTopic("not dead", "@S@`You have my apologies, ##ActorName##. Nay, stay down "
        "and let me tend to you. I marvel that you are alive at all...' @D@says "
        "Berenar and he crouches down to help Galadhel tend ##InitiatorPossessive## wounds.");
    addResponseTopic("berenar interjects", "I'm not dead yet...", "not dead");
    addTopicEvent("not dead", "playerAgainLosesConsciousness");

    addTopic("on the trail", "@S@`Belathon!' @D@bellows Berenar as he "
        "glances at the recent carnage. @S@`Take ##ActorName## and the rest "
        "of your squad and hunt these bastards down.'");
    addTopicInterjection("on the trail",
        "/lib/tutorial/characters/donald/donald.c",
        "you heard the man", 1);

    addTopic("default", "@D@Berenar points to the west and says, @S@`Go!'");
}
