//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Harn lifts a practice blade "
        "from the rack and offers the hilt for you to inspect.");
    addTopic("blade care", "@S@'Wipe the blade dry after use and keep "
        "the edge clean. A sword left wet will punish its owner.'");
    addTopic("balance", "@D@Harn settles the practice blade across "
        "his palm. @S@'Weight alone does not make a good sword. "
        "The balance has to suit the hand that carries it.'");
    addTopic("forge work", "@S@'I work the steel slowly. Rush a "
        "heating or quench and the blade may look sound until the "
        "first hard use.'");
    addTopic("practice", "@D@Harn returns the blade to the rack. "
        "@S@'Learn with a blunted weapon and a patient partner. "
        "A new blade is not a teacher, and a sharp edge punishes "
        "carelessness.'");
    addTopic("commissioned blades", "@S@'For a custom blade, tell "
        "me who will use it, what work it must do, and how it will "
        "be carried. I will not copy a design that cannot be made "
        "sound.'");

    addResponse("first conversation", "Can you check this blade?",
        "@S@'Lay it on the counter. I will check the balance and the edge.'");
    addResponseTopic("first conversation", "Can you check this blade?",
        "blade care");
    addResponse("first conversation", "What makes a blade good?",
        "@S@'It must fit the person using it. A sound edge and proper "
        "balance matter more than a fancy guard.'");
    addResponseTopic("first conversation", "What makes a blade good?",
        "balance");
    addResponse("first conversation", "How long does a blade take to make?",
        "@S@'As long as the steel needs. I will not promise a quick "
        "job if it means sending out poor work.'");
    addResponseTopic("first conversation",
        "How long does a blade take to make?", "forge work");
    addResponse("balance", "Can you change the balance?",
        "@S@'Sometimes. Bring the blade in and let me see its hilt "
        "and weight before I say what can be done.'");
    addResponseTopic("balance", "Can you change the balance?",
        "forge work");
    addResponse("blade care", "What if rust has already started?",
        "@S@'Bring it here. Do not scrape at it with another blade "
        "or you may damage the edge.'");
    addResponse("first conversation", "Can you teach me to use a sword?",
        "@S@'I can show you how a blade should balance, but you "
        "should learn its use from a patient instructor.'");
    addResponseTopic("first conversation",
        "Can you teach me to use a sword?", "practice");
    addResponse("practice", "Can I practice with a live blade?",
        "@S@'Not as a beginner. Start with a blunted practice blade "
        "and learn control before speed.'");
    addResponseTopic("practice", "Can I practice with a live blade?",
        "blade care");
    addResponse("balance", "Can you make a blade to order?",
        "@S@'I can, if the design is sound and the work suits the "
        "steel. Tell me what you need it to do.'");
    addResponseTopic("balance", "Can you make a blade to order?",
        "commissioned blades");
    addResponse("commissioned blades", "Can you copy an heirloom?",
        "@S@'I can study its shape, but I will not promise a copy "
        "until I know the blade can be made safely.'");
    addResponseTopic("commissioned blades",
        "Can you copy an heirloom?", "forge work");
}
