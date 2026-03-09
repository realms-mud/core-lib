//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

private string HoldingRoom =
    "/areas/tol-dhurath/temple-interior/uhrdalen-holding.c";

/////////////////////////////////////////////////////////////////////////////
private void TheReturn()
{
    addTopic("seventh test", "@D@The wispy figure of Uhrdalen "
        "materializes before you. He seems... different. Less guarded. "
        "Almost warm.\n\n@S@'You have returned, ##ActorName##. You have "
        "walked through fire and frost, faced your shadow, lived my "
        "memories, and endured what would break lesser souls. One last "
        "task remains - and it is perhaps the simplest and the hardest.'");

    addResponse("seventh test", "What would you have me do?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::ask##, @S@'What is "
        "this last task?'");
    addResponse("seventh test", "I am ready.",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::nod## firmly, "
        "@S@'I am ready, Uhrdalen.'");
}

/////////////////////////////////////////////////////////////////////////////
private void TheMeaningOfThePoem()
{
    addTopic("the meaning", "@S@'Tell me what the poem means. Not the "
        "words - you can read those on the wall. Tell me what you have "
        "learned. What does it mean to be weak and strong at once? To "
        "burn and freeze? To find no sanctuary yet long for freedom?'");
    addResponseTopic("seventh test", "What would you have me do?",
        "the meaning");
    addResponseTopic("seventh test", "I am ready.", "the meaning");

    addResponse("the meaning", "It is about you... @A@Wisdom@E@",
        "@D@@C@##InitiatorName## carefully ##ResponseInfinitive::reply##, "
        "@S@'The poem is your story, Uhrdalen. Every line is a piece of "
        "your life - the oath, the power, the destruction, the binding. "
        "Weakness and strength were the same choice. You obeyed because "
        "you were too strong to break and too weak to refuse.'");
    addResponsePrerequisite("the meaning", "It is about you... @A@Wisdom@E@",
        (["wisdom":(["type":"attribute", "value" : 4])]), 1);

    addResponse("the meaning", "It is about obedience...",
        "@D@@C@##InitiatorName## thoughtfully ##ResponseInfinitive::say##, "
        "@S@'The poem is about what obedience costs. Every line is a "
        "sacrifice - identity, freedom, peace. To obey without "
        "understanding is to lose yourself.'");

    addResponse("the meaning", "I do not fully understand...",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::admit##, @S@'I will "
        "not pretend to understand it all. But I felt it - in your "
        "memories, in the fire, in the mirror. The poem is pain made "
        "into words.'");
}

/////////////////////////////////////////////////////////////////////////////
private void UhrdalenResponds()
{
    addTopic("uhrdalen responds", "@D@Uhrdalen is silent for a long moment. "
        "When he speaks, his voice is softer than you have ever heard "
        "it.\n\n@S@'You understand more than you know, ##ActorName##. "
        "More than I did, at your age. More than I did for centuries "
        "after. The poem is all of those things. It is my story and it "
        "is a warning and it is the truth about what happens when you "
        "surrender your will to another without question.\n\n"
        "But there is one line you have not yet placed. The last verse. "
        "Do you know what it says?'");
    addResponseTopic("the meaning", "It is about you... @A@Wisdom@E@",
        "uhrdalen responds");
    addResponseTopic("the meaning", "It is about obedience...",
        "uhrdalen responds");
    addResponseTopic("the meaning", "I do not fully understand...",
        "uhrdalen responds");

    addResponse("uhrdalen responds", "I long for freedom restored.",
        "@D@@C@##InitiatorName## quietly ##ResponseInfinitive::say##, "
        "@S@'I long for freedom restored.'");
    addResponse("uhrdalen responds", "Tell me.",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::shake## "
        "##InitiatorPossessive## head, @S@'I do not know.'");
}

/////////////////////////////////////////////////////////////////////////////
private void TheFinalRune()
{
    addTopic("the final rune", "@D@Uhrdalen reaches into the folds of "
        "his veil and produces a fist-sized slab of amethyst. It glows "
        "with a soft, sad light.\n\n@S@'I long for freedom restored.' "
        "@D@He repeats the words as though tasting them.\n\n@S@'That "
        "is my line, ##ActorName##. It has always been mine. I envy you "
        "your freedom - the freedom to choose, to leave, to act. I chose "
        "obedience and lost everything. You chose to understand and gained "
        "what I could not.'\n\n@D@He holds out the rune. @S@'Take it. "
        "Complete the poem. And when you leave this place, remember that "
        "obedience without understanding is slavery, but obedience with "
        "understanding is wisdom.'");
    addResponseTopic("uhrdalen responds", "I long for freedom restored.",
        "the final rune");
    addResponseTopic("uhrdalen responds", "Tell me.", "the final rune");

    addResponse("the final rune", "Thank you, Uhrdalen.",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::bow## "
        "##InitiatorPossessive## head, @S@'Thank you, Uhrdalen. I will "
        "remember.'");
    addResponseEffect("the final rune", "Thank you, Uhrdalen.",
        (["give": "/areas/tol-dhurath/objects/rune-envy.c"]));

    addResponse("the final rune", "Will you be free?",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::ask##, @S@'And you? "
        "Will you find freedom?'");
    addResponseEffect("the final rune", "Will you be free?",
        (["give": "/areas/tol-dhurath/objects/rune-envy.c"]));
}

/////////////////////////////////////////////////////////////////////////////
private void TheSeventhVerse()
{
    addTopic("seventh verse", "@D@Uhrdalen's form steadies for a moment. "
        "Something that might be a smile crosses his skeletal features."
        "\n\n@S@'Perhaps. Perhaps completing this poem, after all these "
        "centuries, is the first step. You have given me something I had "
        "forgotten - hope that the cycle can be broken.'\n\n@D@His gaze "
        "drifts toward the pedestals one final time.\n\n@S@'One last "
        "verse, for you will need it:\nThe crimson fires of war rage "
        "to the north.\nThe sapphire tears of sorrow fall to the south.\n"
        "The pale silence of surrender drifts to the east.\nThe emerald "
        "bite of envy lingers to the west.'\n\n@D@He fixes you with "
        "his hollow gaze.\n\n@S@'Place every rune upon the wall, "
        "##ActorName##. Every verse must be whole before the poem can "
        "speak its truth. Only then will your task here be complete.'");
    addResponseTopic("the final rune", "Thank you, Uhrdalen.",
        "seventh verse");
    addResponseTopic("the final rune", "Will you be free?",
        "seventh verse");

    addResponse("seventh verse", "I will see it done.",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::nod##. "
        "@S@'I will see it done.'");
    addResponse("seventh verse", "Every rune. I understand.",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::glance## "
        "at the wall of runes. @S@'Every rune. I understand.'");
}

/////////////////////////////////////////////////////////////////////////////
private void UhrdalensFarewell()
{
    addTopic("farewell", "@D@The wispy figure bows deeply - a gesture "
        "of genuine respect from a being who has had little cause for "
        "it.\n\n@S@'Go now, ##ActorName##. Complete what you came here "
        "to do. The path is open to you.'\n\n@D@Uhrdalen fades from "
        "view. This time, it feels like a farewell rather than a "
        "disappearance.");
    addResponseTopic("seventh verse", "I will see it done.", "farewell");
    addResponseTopic("seventh verse", "Every rune. I understand.",
        "farewell");

    addResponse("farewell", "@I@Continue@E@", "@I@Continue@E@");
    addResponseEffect("farewell", "@I@Continue@E@",
        (["move": HoldingRoom]));
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    TheReturn();
    TheMeaningOfThePoem();
    UhrdalenResponds();
    TheFinalRune();
    TheSeventhVerse();
    UhrdalensFarewell();
}
