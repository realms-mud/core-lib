//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Aven closes a volume of law "
        "and listens. @S@'A precedent can guide a decision, but it "
        "cannot decide a new case by itself.'");
    addTopic("precedent", "@S@'I compare the facts and the older "
        "rulings. The king hears counsel; a petitioner still needs "
        "to make the matter clear.'");
    addTopic("petition", "@S@'Put the request in writing and give "
        "the scribe a clear account. Do not confuse an audience "
        "with a promise of judgment.'");

    addResponse("first conversation", "What does a legal adviser do?",
        "@D@You notice the marked pages beside him.");
    addResponseTopic("first conversation",
        "What does a legal adviser do?", "precedent");
    addResponse("first conversation", "How do I bring a matter to court?",
        "@S@'Begin with a written petition. The household can tell "
        "you where it should be delivered.'");
    addResponseTopic("first conversation",
        "How do I bring a matter to court?", "petition");
    addResponse("precedent", "Can an old ruling settle my case?",
        "@S@'It may be relevant. The facts and the law both matter; "
        "I will not promise an outcome before they are heard.'");
}
