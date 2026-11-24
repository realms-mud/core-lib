//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("camp aftermath", "@D@Galadhel looks over the fallen "
        "Aegis, then turns back to you. @S@'We owe them a proper "
        "rest, but the robed ones have a head start. We cannot "
        "pretend either duty matters less.'");
    addTopic("honor the fallen", "@D@Her voice softens. @S@'Take "
        "their personal effects so their families can remember them "
        "as they were. Then help Berenar prepare the pyre.'");
    addTopicInterjection("honor the fallen",
        "/areas/argalen-keep/characters/halgaladh/halgaladh.c",
        "our dead", 1);
    addTopic("hunt the robed ones", "@D@Galadhel checks her bow. "
        "@S@'If they reach their masters, they will report what "
        "they learned here. We should follow while their trail is "
        "still warm.'");
    addTopicInterjection("hunt the robed ones",
        "/areas/argalen-keep/characters/halgaladh/halgaladh.c",
        "camp investigation", 1);
    addTopic("the prisoner", "@D@She keeps her arrow trained on "
        "the captive. @S@'We need answers, but we are not executioners. "
        "Keep him alive long enough to learn why the dead attacked us.'");
    addTopic("question the prisoner", "@D@Galadhel watches the "
        "captive carefully. @S@'We need to learn what this place "
        "is and who commands it. Ask plainly, and listen for what "
        "he avoids saying.'");
    addTopic("protect the prisoner", "@S@'He is frightened and "
        "wounded. If we promise safety, we must mean it. If we "
        "cannot, we should not pretend otherwise.'");
    addTopic("press the prisoner", "@D@Her expression hardens. "
        "@S@'We can make our questions clear without cruelty. "
        "Threats may get an answer, but they will not make it true.'");
    addTopic("leave the prisoner", "@S@'If he refuses to speak, "
        "we decide whether to take him with us or leave him under "
        "guard. We do not kill a captive to save ourselves the "
        "trouble of deciding.'");

    addResponse("camp aftermath", "We should honor the fallen first.",
        "@S@'Then help Berenar gather their effects and prepare "
        "the pyre. We will not leave them forgotten.'");
    addResponseTopic("camp aftermath",
        "We should honor the fallen first.", "honor the fallen");
    addResponse("camp aftermath", "We should pursue the enemy.",
        "@S@'Agreed. Berenar can report to Aredec while we follow "
        "the trail.'");
    addResponseTopic("camp aftermath",
        "We should pursue the enemy.", "hunt the robed ones");

    addResponse("honor the fallen", "We cannot stay long.",
        "@S@'We will be quick. A farewell need not become a delay.'");
    addResponseTopic("honor the fallen", "We cannot stay long.",
        "hunt the robed ones");
    addResponse("honor the fallen", "I will help Berenar.",
        "@S@'Thank you. I will make sure the others are ready to move.'");

    addResponse("hunt the robed ones", "What if the trail is a trap?",
        "@S@'Then we watch our flanks and move together. We will "
        "not charge blindly into a narrow passage.'");
    addResponseTopic("hunt the robed ones",
        "What if the trail is a trap?", "the prisoner");
    addResponse("hunt the robed ones", "What about the captive?",
        "@S@'We take him with us under guard. He may know why "
        "these creatures were sent against our camp.'");
    addResponseTopic("hunt the robed ones", "What about the captive?",
        "the prisoner");
    addResponse("hunt the robed ones", "Can we question him first?",
        "@S@'Yes, but we must not let the enemy gain more ground "
        "while we argue over every question.'");
    addResponseTopic("hunt the robed ones", "Can we question him first?",
        "question the prisoner");

    addResponse("question the prisoner", "Try reason first.",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::speak## calmly "
        "to the captive. @S@'We want to understand what happened. "
        "Tell us what you can, and we will hear you out.'");
    addResponseTopic("question the prisoner", "Try reason first.",
        "protect the prisoner");
    addResponse("question the prisoner", "Make him afraid to refuse.",
        "@D@@C@##InitiatorName## ##ResponseInfinitive::warn## the "
        "captive that time is short. @S@'Answer our questions, "
        "and you may yet leave this place alive.'");
    addResponsePrerequisite("question the prisoner",
        "Make him afraid to refuse.",
        (["intimidation":(["type":"skill", "value":5])]), 1);
    addResponseTopic("question the prisoner",
        "Make him afraid to refuse.", "press the prisoner");
    addResponse("question the prisoner", "I will not question him.",
        "@S@'Then stand watch while the rest of us decide what "
        "to do with him.'");
    addResponseTopic("question the prisoner",
        "I will not question him.", "leave the prisoner");

    addResponse("protect the prisoner", "I cannot promise his safety.",
        "@S@'Then do not make that promise. Tell him only what "
        "you can honestly offer.'");
    addResponseTopic("protect the prisoner",
        "I cannot promise his safety.", "press the prisoner");
    addResponse("protect the prisoner", "Let him speak in his own time.",
        "@S@'We can give him a moment. We cannot give him the whole day.'");
    addResponseTopic("protect the prisoner",
        "Let him speak in his own time.", "leave the prisoner");
    addResponse("press the prisoner", "Then we stop here.",
        "@S@'Agreed. Step back and let him decide whether he will speak.'");
    addResponseTopic("press the prisoner",
        "Then we stop here.", "leave the prisoner");
    addResponse("leave the prisoner", "I will stay with him.",
        "@S@'Good. Make certain no one harms him while we are gone.'");
    addResponse("leave the prisoner", "We should take him along.",
        "@S@'Then keep him close and assign someone to watch him.'");

    addResponse("the prisoner", "Should we trust what he says?",
        "@S@'No. We should hear him, check his claims, and keep "
        "our weapons ready.'");
    addResponse("the prisoner", "We should kill him now.",
        "@S@'No. He is in our custody. We can defend ourselves "
        "without becoming the thing we oppose.'");
}
