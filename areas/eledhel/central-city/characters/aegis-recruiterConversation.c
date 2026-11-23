//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Sergeant Lethar studies your "
        "bearing before he answers. @S@'The Aegis trains for service, "
        "not for a title or a polished breastplate.'");
    addTopic("enrollment", "@S@'If you are prepared to serve, use "
        "'enroll with Lethar'. The guild's exclusions and your own "
        "history still apply.'");
    addTopic("lessons", "@S@'Ask for 'lessons from Lethar' to see "
        "what the academy can teach. Your level, research, and "
        "available points determine what you can learn.'");

    addResponse("first conversation", "How do I join the Aegis Guard?",
        "@D@Lethar sets the enrollment ledger beside the notice board.");
    addResponseTopic("first conversation",
        "How do I join the Aegis Guard?", "enrollment");
    addResponse("first conversation", "Can you teach me?",
        "@S@'The academy teaches the Guard's established disciplines. "
        "I will show you the curriculum and its requirements.'");
    addResponseTopic("first conversation", "Can you teach me?", "lessons");
    addResponse("enrollment", "Can I join another order as well?",
        "@S@'Check the guild's exclusions before you make a choice. "
        "Some oaths cannot be held together.'");
}
