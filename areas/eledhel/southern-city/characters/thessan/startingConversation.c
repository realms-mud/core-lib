//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@S@'Please keep your hands clear "
        "of the display glass. I am happy to show you a piece if you "
        "tell me what you are looking for.'");
    addTopic("valuations", "@S@'I can judge the cut and the setting. "
        "The value of a stone also depends on where it came from and "
        "who can vouch for it.'");
    addTopic("commissioned work", "@D@Thessan puts away the loupe. "
        "@S@'For a commission, tell me the size, the metal, and "
        "whether the piece is for daily wear or a special occasion. "
        "Good work begins with clear expectations.'");
    addTopic("heirlooms", "@S@'An heirloom is worth more than its "
        "materials. I can repair it, but I will ask before changing "
        "anything that carries a family mark.'");
    addTopic("design choices", "@D@Thessan opens a sketchbook. "
        "@S@'A design must fit the person who will wear it. We "
        "can choose a setting, a stone, or a detail that has meaning "
        "without making the piece fragile.'");
    addTopic("provenance", "@S@'A mark can tell us who made a piece "
        "or who owned it before. It cannot prove the whole history, "
        "so I record what I know and leave the rest as a question.'");

    addResponse("first conversation", "Can you value a stone?",
        "@S@'Bring it into the light and let me see the whole face.'");
    addResponseTopic("first conversation", "Can you value a stone?",
        "valuations");
    addResponse("first conversation", "Can you make a custom piece?",
        "@S@'Yes. Tell me what you have in mind and what materials "
        "you want to use.'");
    addResponseTopic("first conversation", "Can you make a custom piece?",
        "commissioned work");
    addResponse("first conversation", "Can you repair an heirloom?",
        "@S@'I can inspect it and explain what can be repaired "
        "without altering its character.'");
    addResponseTopic("first conversation",
        "Can you repair an heirloom?", "heirlooms");
    addResponse("valuations", "Can you tell if a stone is genuine?",
        "@S@'I can examine its cut, color, and flaws. I will tell "
        "you what I can establish and what remains uncertain.'");
    addResponseTopic("valuations", "Can you tell if a stone is genuine?",
        "commissioned work");
    addResponse("heirlooms", "Would you change a family setting?",
        "@S@'Only with the owner's consent. Sometimes a careful "
        "repair is better than making something new.'");
    addResponseTopic("heirlooms",
        "Would you change a family setting?", "provenance");
    addResponse("commissioned work", "Can I choose every detail?",
        "@S@'You may choose what matters to you. I will tell you "
        "when a choice would make the piece less secure.'");
    addResponseTopic("commissioned work",
        "Can I choose every detail?", "design choices");
    addResponse("design choices", "Can you copy a family emblem?",
        "@S@'If you have the right to use it and can show me the "
        "design, I can work it into the piece.'");
    addResponseTopic("design choices",
        "Can you copy a family emblem?", "heirlooms");
    addResponse("provenance", "Can you identify the maker's mark?",
        "@S@'I can compare it with marks I know, but I will be "
        "careful not to claim more than the mark can tell us.'");
    addResponseTopic("provenance",
        "Can you identify the maker's mark?", "valuations");
}
