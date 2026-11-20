//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Tavren listens to the mill "
        "wheel before answering. @S@'Keep clear of the stones while "
        "they are turning; the grain can wait.'");
    addTopic("the mill", "@S@'The brook is narrow here, so the "
        "sluice is shared with the gardens. A clean wheel and a "
        "fair tally matter more than a full hopper.'");
    addResponse("first conversation", "What does the mill serve?",
        "@S@'The village households and the manor stores. Each "
        "delivery is weighed before it is ground.'");
    addResponse("first conversation", "Who controls the water?",
        "@S@'The reeve keeps the schedule; I follow the turn set "
        "for the wheel.'");
    addResponseTopic("first conversation", "Who controls the water?",
        "the mill");
    addResponse("the mill", "Where can I buy flour?",
        "@S@'Ask at the common store by the green. This floor is "
        "work space, not a public counter.'");
}
