//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
private void ViliasAppears()
{
    addTopic("first conversation", "@D@Some mist forms a few feet to the "
        "east. As it thickens, it begins to take form. The figure looks "
        "vaguely humanoid. As the mist coalesces, it takes on the form of a "
        "woman dressed in a flowing midnight blue robe. She is a tall, "
        "raven-haired, grey-eyed woman of surpassing beauty. She doesn't look "
        "quite human - whether that's due to her visage or the fact that "
        "she's ethereal is unclear.\n\nSensing the party tense, she smiles "
        "brightly and says in a pleasant, somewhat demure voice, @S@'Nay, I "
        "am no foe. In fact, you should thank me.' @D@She grins impishly at "
        "this and, in a sweet, musical voice adds, @S@'For you were about "
        "to get yourselves killed.'");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    ViliasAppears();

    addTopic("why did you help", "@D@Vilias studies you with an "
        "amused, unreadable expression. @S@'You are alive, are you "
        "not? It is possible to benefit from the same outcome without "
        "sharing a cause.'");
    addTopic("the souls", "@S@'Your people speak of death as though "
        "it were always an ending. Some souls are taken where they "
        "can be restored. I have helped a few find their way back.'");
    addTopic("Xyris", "@D@Her smile thins. @S@'My master does not "
        "welcome interference. You have already seen what becomes "
        "of those who mistake his patience for weakness.'");
    addTopic("our bargain", "@D@Vilias tilts her head. @S@'I gave "
        "you my word that I would heal you if you asked sincerely. "
        "You did. I kept it. Do not confuse a bargain kept with "
        "affection.'");
    addTopic("will you return", "@S@'Perhaps. I go where I choose, "
        "and I have no intention of promising you a schedule.'");
    addTopic("what do you want", "@D@She steps closer, her gaze "
        "fixed on yours. @S@'A world in which my own purposes remain "
        "possible. That is all you need to know for now.'");

    addResponse("first conversation", "Why did you help us?",
        "@S@'Because our interests crossed for a moment.'");
    addResponseTopic("first conversation", "Why did you help us?",
        "why did you help");
    addResponse("first conversation", "What happens to the souls?",
        "@S@'That depends on where they are sent.'");
    addResponseTopic("first conversation", "What happens to the souls?",
        "the souls");
    addResponse("first conversation", "Are you afraid of Xyris?",
        "@S@'Fear is useful when it keeps one attentive.'");
    addResponseTopic("first conversation", "Are you afraid of Xyris?",
        "Xyris");
    addResponse("first conversation", "Why did you heal me?",
        "@S@'You called upon the bargain we made.'");
    addResponseTopic("first conversation", "Why did you heal me?",
        "our bargain");
    addResponse("first conversation", "Will I see you again?",
        "@S@'That depends on whether our paths cross.'");
    addResponseTopic("first conversation", "Will I see you again?",
        "will you return");
    addResponse("why did you help", "So you are not our ally?",
        "@S@'Do not ask me to wear a label that serves your comfort. "
        "Watch what I do and decide what it means.'");
    addResponseTopic("why did you help", "So you are not our ally?",
        "what do you want");
    addResponse("the souls", "Why would you return them?",
        "@S@'Because they still have a purpose of their own. I do "
        "not need to explain that to you.'");
    addResponse("Xyris", "What does he want?",
        "@S@'More than you can safely give him. Leave the matter "
        "there.'");
    addResponse("our bargain", "Can I trust your word?",
        "@S@'You can trust that I keep bargains I choose to make. "
        "You should not assume that I have made any others.'");
    addResponse("what do you want", "Will you tell me more?",
        "@S@'Not today. You have already had more answers than "
        "most would receive.'");
}
