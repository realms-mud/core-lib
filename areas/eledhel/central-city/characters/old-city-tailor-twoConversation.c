//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Nethwen folds a length of "
        "undyed cloth. @S@'A clean seam is worth more than a bright "
        "color. What are you looking for?'");
    addTopic("everyday clothing", "@S@'I make work clothes that can "
        "take a hard week. If a sleeve tears, bring it in before the "
        "whole seam gives way.'");
    addTopic("alterations", "@S@'A garment should fit the person who "
        "wears it. I can shorten a hem or let out a seam without "
        "making the whole thing over.'");
    addResponse("first conversation", "What do you keep in stock?",
        "@D@She points to the folded cloth behind the counter.");
    addResponseTopic("first conversation", "What do you keep in stock?",
        "everyday clothing");
    addResponse("everyday clothing", "Can you alter a coat?",
        "@D@Nethwen measures an imaginary sleeve with her hands.");
    addResponseTopic("everyday clothing", "Can you alter a coat?",
        "alterations");
}
