//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Vethra checks the seal on a small "
        "glass jar before turning to you.");
    addTopic("arcane goods", "@S@'My shelves hold common reagents and "
        "well-made instruments. Anything dangerous or rare requires "
        "a proper license and a serious conversation.'");
    addTopic("responsible study", "@D@Vethra checks the seals on "
        "the jars before answering. @S@'Know what you are handling, "
        "keep it contained, and do not experiment around other people. "
        "I will not sell a mystery in a bottle.'");
    addTopic("finding supplies", "@S@'Tell me the work you are doing "
        "and what training you have. The right instrument is safer "
        "than a shelf full of things you do not understand.'");
    addTopic("learning safely", "@S@'Begin with a teacher, a clear "
        "workspace, and materials you can identify. Keep notes on "
        "what you do, including what did not work.'");
    addTopic("restricted materials", "@D@Vethra checks the seal "
        "again. @S@'A restriction is not an invitation to bargain. "
        "Tell me your purpose and I will explain what I can provide.'");

    addResponse("first conversation", "What do you stock?",
        "@S@'Supplies for study, not shortcuts. Tell me what you are "
        "working on and I can point you to the right shelf.'");
    addResponseTopic("first conversation", "What do you stock?",
        "arcane goods");
    addResponse("first conversation", "Can I buy rare reagents?",
        "@S@'That depends on the reagent and your purpose. Tell me "
        "what you need before I decide whether I can help.'");
    addResponseTopic("first conversation",
        "Can I buy rare reagents?", "finding supplies");
    addResponse("first conversation", "How do you store these safely?",
        "@S@'Each jar is labeled and sealed. Keep unknown materials "
        "separate and never mix them without instruction.'");
    addResponseTopic("first conversation",
        "How do you store these safely?", "responsible study");
    addResponse("arcane goods", "Why are some items restricted?",
        "@S@'Because a careless buyer can harm themselves and the "
        "people around them. Training and purpose both matter.'");
    addResponseTopic("arcane goods", "Why are some items restricted?",
        "responsible study");
    addResponse("finding supplies", "What should a beginner start with?",
        "@S@'A notebook, a sound instrument, and a teacher. "
        "Do not mistake buying supplies for learning how to use them.'");
    addResponseTopic("finding supplies",
        "What should a beginner start with?", "learning safely");
    addResponse("responsible study", "What if a seal is broken?",
        "@S@'Do not handle the contents. Mark the jar and bring it "
        "to me or another trained keeper.'");
    addResponseTopic("responsible study",
        "What if a seal is broken?", "restricted materials");
    addResponse("learning safely", "Can I experiment at home?",
        "@S@'Only with safe materials and sound instruction. Keep "
        "your work away from children, animals, and open flame.'");
    addResponseTopic("learning safely",
        "Can I experiment at home?", "responsible study");
    addResponse("restricted materials", "What would earn your trust?",
        "@S@'Honest answers, proper training, and a willingness "
        "to accept no when a material is not appropriate.'");
    addResponseTopic("restricted materials",
        "What would earn your trust?", "finding supplies");
}
