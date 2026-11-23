//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Averin sets down a quill and "
        "looks up from the open ledger.");
    addTopic("petitions", "@S@'Petitions are entered with the date, "
        "the names of those involved, and a plain account of the "
        "matter. The judge decides what must be heard.'");
    addTopic("records", "@S@'A record is not a rumor. I preserve "
        "what was submitted and note any correction rather than "
        "silently changing the account.'");

    addResponse("first conversation", "How do I bring a matter here?",
        "@S@'Give a clerk a clear account and the names of any "
        "witnesses. We will enter it for review.'");
    addResponseTopic("first conversation",
        "How do I bring a matter here?", "petitions");
    addResponse("first conversation", "Can I read the court records?",
        "@S@'Some records are public. Others contain testimony "
        "that must be protected.'");
    addResponseTopic("first conversation",
        "Can I read the court records?", "records");
}
