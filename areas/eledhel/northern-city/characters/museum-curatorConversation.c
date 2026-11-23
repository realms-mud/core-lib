//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Mereth straightens a small label "
        "beside a display case. @S@'The museum keeps a modest record of "
        "the capital and the coast around it.'");
    addTopic("harbor displays", "@S@'The harbor objects tell of work "
        "as much as trade: nets, fittings, and tools repaired until "
        "their owners could afford new ones.'");
    addTopic("careful history", "@S@'A display label tells you what "
        "the evidence supports. Where accounts disagree, the difference "
        "belongs in the record too.'");

    addResponse("first conversation", "What is in the harbor displays?",
        "@D@You nod toward the cases nearest the entrance.");
    addResponseTopic("first conversation",
        "What is in the harbor displays?", "harbor displays");
    addResponse("first conversation", "How do you decide what is true?",
        "@S@'We keep the evidence with the claim and distinguish "
        "a documented fact from a likely explanation.'");
    addResponseTopic("first conversation",
        "How do you decide what is true?", "careful history");
    addResponse("harbor displays", "Are these objects from one ship?",
        "@S@'No. The collection is assembled from different people "
        "and times. We label each known origin separately.'");
    addResponseTopic("harbor displays",
        "Are these objects from one ship?", "careful history");
}
