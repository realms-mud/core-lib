//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Orvan checks a cooling bar "
        "with a practiced eye.");
    addTopic("smelting", "@S@'The heat must be steady and the ore "
        "sorted before it reaches the furnace. A rushed pour wastes "
        "good material and puts everyone nearby at risk.'");
    addTopic("metal quality", "@S@'I test each bar for cracks and "
        "weak spots before it leaves. The smith needs sound stock, "
        "not a promise that it will hold.'");

    addResponse("first conversation", "What happens here?",
        "@S@'We separate the ore, melt it, and cast bars for the "
        "city's smiths.'");
    addResponseTopic("first conversation", "What happens here?",
        "smelting");
    addResponse("smelting", "How do you know a bar is sound?",
        "@S@'Let it cool, then inspect it before it is marked for "
        "use. A bad casting is rejected.'");
    addResponseTopic("smelting", "How do you know a bar is sound?",
        "metal quality");
}
