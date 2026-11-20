//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Nerith lifts a bundle of leaves "
        "to check its scent, then sets it carefully back on the shelf.");
    addTopic("gathering", "@S@'I gather only what the plants can spare. "
        "Take too much from one patch and next year there is nothing "
        "left to gather.'");
    addTopic("plant seasons", "@S@'The same plant can be easy to "
        "recognize in flower and difficult to tell from its neighbors "
        "when it is young. Learn the season as well as the leaf.'");
    addTopic("safe use", "@S@'Never put an unknown plant in a pot or "
        "a wound. Some look alike and have very different effects. "
        "Ask before you use what you do not know.'");
    addTopic("gathering ethics", "@S@'Leave enough for the plant to "
        "flower and seed. If a patch is scarce, gather elsewhere or "
        "come back another season.'");
    addTopic("drying herbs", "@D@Nerith checks the hanging bundles. "
        "@S@'Dry each plant in the way it needs. Too much heat or "
        "damp can spoil a good harvest before it reaches the jar.'");

    addResponse("first conversation", "Can you teach me to identify herbs?",
        "@S@'Start with what grows by the road. Learn its leaves, smell, "
        "and season before you ever try to use it.'");
    addResponseTopic("first conversation",
        "Can you teach me to identify herbs?", "gathering");
    addResponse("first conversation", "What do you gather now?",
        "@S@'It depends on the season. I take only what I can identify "
        "and leave enough for the patch to grow back.'");
    addResponseTopic("first conversation", "What do you gather now?",
        "plant seasons");
    addResponse("first conversation", "Can I use these for medicine?",
        "@S@'Not until you know exactly what they are and how they "
        "are prepared. A healer or apothecary can help you with that.'");
    addResponseTopic("first conversation",
        "Can I use these for medicine?", "safe use");
    addResponse("gathering", "How do I avoid taking too much?",
        "@S@'Move between patches and leave the strongest plants "
        "to seed. A careful gatherer thinks about next season.'");
    addResponseTopic("gathering", "How do I avoid taking too much?",
        "plant seasons");
    addResponse("plant seasons", "What should a beginner learn first?",
        "@S@'One plant at a time. Learn where it grows, when it "
        "flowers, and what marks it apart from anything dangerous.'");
    addResponseTopic("plant seasons",
        "What should a beginner learn first?", "safe use");
    addResponse("gathering", "What if a patch is nearly gone?",
        "@S@'Leave it alone. A gatherer should think of next year "
        "as well as today's basket.'");
    addResponseTopic("gathering", "What if a patch is nearly gone?",
        "gathering ethics");
    addResponse("gathering ethics", "How do you preserve what you gather?",
        "@S@'Sort it carefully and dry it where air can move. "
        "Different leaves need different care.'");
    addResponseTopic("gathering ethics",
        "How do you preserve what you gather?", "drying herbs");
    addResponse("drying herbs", "Can I dry an unknown plant?",
        "@S@'Do not. First learn what it is and whether it is "
        "safe to handle. Drying does not make every plant harmless.'");
    addResponseTopic("drying herbs", "Can I dry an unknown plant?",
        "safe use");
}
