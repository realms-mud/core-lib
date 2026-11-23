//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

protected void Setup()
{
    addTopic("first conversation", "@D@Barad studies the wear on a "
        "breastplate before answering. @S@'Armor must fit before it "
        "can protect anyone.'");
    addTopic("armor orders", "@S@'I stock serviceable pieces and can "
        "alter a fit. A guard who cannot lift an arm freely is no safer "
        "for wearing more metal.'");
    addTopic("repairs", "@S@'Bring damaged armor here before you wear "
        "it again. A bent fastening can fail under less strain than "
        "you expect.'");
    addResponse("first conversation", "What armor do you make?",
        "@D@He indicates the fittings arranged on the wall.");
    addResponseTopic("first conversation", "What armor do you make?",
        "armor orders");
    addResponse("armor orders", "Will you repair a broken fastening?",
        "@D@Barad reaches for a set of small tools.");
    addResponseTopic("armor orders", "Will you repair a broken "
        "fastening?", "repairs");
}
