//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@S@'The boats work the inlet when "
        "the weather allows. The King's Road brings our grain and salt.'");
    addResponse("first conversation", "Is the southern coast safe?",
        "@S@'Most days the road is quiet. The broken beacon farther south "
        "is another matter; its stones shelter people who do not fish.'");
}
