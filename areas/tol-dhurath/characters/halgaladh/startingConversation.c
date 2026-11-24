//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/modules/conversations/baseConversation.c";

private mapping scionsKnowledge = ([
    "learned through books or the trial":([
        "type":"any of",
        "prerequisites":({
            ([
                "Scions history":([
                    "type":"observation",
                    "criteria":({
                        ([
                            "type":"knowledge.book.read",
                            "subject":
                                "/areas/items/books/scions-of-dhuras.c"
                        ]),
                        ([
                            "type":"knowledge.book.read",
                            "subject":"/areas/items/books/"
                                "on-the-matter-of-queen-bryleth.c"
                        ]),
                        ([
                            "type":"knowledge.book.read",
                            "subject":
                                "/areas/items/books/the-vanity-of-queens.c"
                        ])
                    }),
                    "value":1
                ])
            ]),
            ([
                "/areas/tol-dhurath/state-machine/tol-dhurath-quest.c":([
                    "type":"quest"
                ])
            ])
        })
    ])
]);

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Halgaladh studies you for a "
        "moment, then his stern expression softens. @S@'It is good "
        "to see you at home. We have known one another too long for "
        "ceremony. There is something on the western road we should "
        "discuss, but I will not mistake friendship for an order.'");
    addTopic("western reports", "@D@Halgaladh rests one hand on the "
        "courtyard wall and looks toward the village. @S@'Two farm "
        "families have seen unfamiliar carts taking the old western "
        "track toward Tol-Dhurath. No one has asked the keep for "
        "soldiers, and a rumor is not proof. I would rather learn "
        "what is happening before someone is hurt.'");
    addTopic("old friends", "@D@Halgaladh's voice grows quieter. "
        "@S@'I have stood beside you since we were children. That "
        "does not mean I expect you to follow me into danger. If we "
        "go, we agree on a route, keep watch for one another, and "
        "turn back if the evidence calls for it.'");
    addRepeatableTopic("default", "@D@Halgaladh waits, patient and "
        "attentive, for you to choose what to discuss.");
    addTopic("scions of dhuras", "@S@'That seems like a reasonable secondary "
        "goal.' @D@notes Halgaladh. @S@'Returning them to the Scions of Dhuras "
        "would bring both us and the king quite a bit of goodwill from that "
        "order.'");

    addTopic("our oath", "@D@Halgaladh considers the question before "
        "answering. @S@'The oath is not a decoration or a right to "
        "command. It is a promise to place the safety of the kingdom "
        "and its people above our comfort.'");
    addTopicInterjection("our oath",
        "/areas/argalen-keep/characters/galadhel/galadhel.c",
        "the squad", 1);
    addTopic("Aegis history", "@S@'The order has changed as Eledhel "
        "has changed. Its purpose has not: stand between the realm "
        "and those who would use power without responsibility.'");
    addTopic("the fallen", "@D@His expression grows grave. @S@'We "
        "honor the dead by remembering them clearly, not by letting "
        "grief turn them into a reason to abandon the living.'");
    addTopic("the company", "@S@'A unit is strongest when every "
        "member knows what the others can do and trusts them to do "
        "it. Rank cannot replace that work.'");
    addTopic("leadership", "@D@Halgaladh considers the question. "
        "@S@'A leader sets a course, but must listen when someone "
        "sees a danger or a better way. Authority is not an excuse "
        "to stop thinking.'");
    addTopic("grief", "@S@'We do not honor our friends by pretending "
        "we feel nothing. We honor them by carrying what they taught "
        "us into the choices still before us.'");
    addTopic("the Scions", "@D@He nods once. @S@'The Scions of "
        "Dhuras have their own duties and their own history. If "
        "we can return them safely, it may strengthen the trust "
        "between our orders.'");
    addTopic("Galadhel", "@D@Halgaladh gives a small nod toward "
        "Galadhel. @S@'She has carried more than she admits. She "
        "does not need anyone to pity her; she does need people to "
        "stand beside her.'");

    addTopicPrerequisite("scions of dhuras", scionsKnowledge);
    addTopicPrerequisite("the Scions", scionsKnowledge);

    addResponse("first conversation", "What is the Aegis oath?",
        "@S@'A promise of service, not a promise of comfort.'");
    addResponseTopic("first conversation", "What is the Aegis oath?",
        "our oath");
    addResponse("first conversation", "What have you heard on the west road?",
        "@D@You ask about the travelers reported near the farms.");
    addResponseTopic("first conversation",
        "What have you heard on the west road?", "western reports");
    addResponse("first conversation", "Do you want me to come with you?",
        "@D@You ask whether he is inviting you or giving an order.");
    addResponseTopic("first conversation",
        "Do you want me to come with you?", "old friends");
    addResponse("first conversation", "Let's investigate Tol-Dhurath together.",
        "@D@You agree to join your friends on the western road.");
    addResponseEvent("first conversation",
        "Let's investigate Tol-Dhurath together.", "startTolDhurath");
    addResponse("western reports", "Let's investigate Tol-Dhurath together.",
        "@D@You agree to join your friends on the western road.");
    addResponseEvent("western reports",
        "Let's investigate Tol-Dhurath together.", "startTolDhurath");
    addResponse("western reports", "Let's wait until we know more.",
        "@D@You tell Halgaladh that you want more information first.");
    addResponseTopic("western reports",
        "Let's wait until we know more.", "default");
    addResponse("old friends", "I will go with you.",
        "@D@You agree to travel with your friends.");
    addResponseEvent("old friends", "I will go with you.",
        "startTolDhurath");
    addResponse("old friends", "I need time to decide.",
        "@D@You tell Halgaladh that you are not ready to leave yet.");
    addResponseTopic("old friends", "I need time to decide.", "default");
    addResponse("default", "Let's investigate Tol-Dhurath together.",
        "@D@You agree to join your friends on the western road.");
    addResponseEvent("default", "Let's investigate Tol-Dhurath together.",
        "startTolDhurath");
    addResponse("first conversation", "How does the order work?",
        "@S@'We learn our history so that we can make better "
        "choices in the present.'");
    addResponseTopic("first conversation", "How does the order work?",
        "Aegis history");
    addResponse("first conversation", "How do you honor fallen comrades?",
        "@S@'First by seeing that the living are safe.'");
    addResponseTopic("first conversation",
        "How do you honor fallen comrades?", "the fallen");
    addResponse("first conversation", "What makes a strong unit?",
        "@S@'Trust, shared discipline, and knowing when another "
        "person is better suited to lead.'");
    addResponseTopic("first conversation", "What makes a strong unit?",
        "the company");
    addResponse("our oath", "Can an Aegis refuse an order?",
        "@S@'An Aegis must use judgment. Blind obedience can "
        "betray the very people the oath exists to protect.'");
    addResponse("Aegis history", "Why study the past?",
        "@S@'So we can recognize old failures when they return "
        "wearing new names.'");
    addResponse("the fallen", "Does grief make us weaker?",
        "@S@'Grief reminds us what is at stake. We must not let it "
        "make every decision for us.'");
    addResponse("the company", "How do comrades earn trust?",
        "@S@'By speaking honestly, doing what they promise, and "
        "standing together when the cost becomes real.'");
    addResponseTopic("the company", "How do comrades earn trust?",
        "leadership");
    addResponse("western reports", "What if the carts are harmless?",
        "@S@'Then we will have lost an afternoon and learned more "
        "about our neighbors. That is a better outcome than letting "
        "fear choose our actions.'");
    addResponse("old friends", "What do you remember about our childhood?",
        "@D@Halgaladh smiles at the memory. @S@'You once convinced "
        "me that the keep's old well had a stairway beneath it. "
        "Galadhel found the loose stone, and we spent the afternoon "
        "arguing over who would go first. None of us did.'");
    addResponseTopic("old friends",
        "What do you remember about our childhood?", "the company");
    addResponse("our oath", "What if an order puts someone at risk?",
        "@S@'Then the leader must hear the warning and weigh it "
        "against the mission. We do not spend lives carelessly.'");
    addResponseTopic("our oath",
        "What if an order puts someone at risk?", "leadership");
    addResponse("leadership", "What if the squad disagrees?",
        "@S@'Hear each concern, make the decision, and explain "
        "what matters. Once we move, we move together.'");
    addResponseTopic("leadership", "What if the squad disagrees?",
        "the company");
    addResponse("the fallen", "How do we keep going after a loss?",
        "@S@'We grieve, we remember, and we protect the living. "
        "None of those duties cancels the others.'");
    addResponseTopic("the fallen",
        "How do we keep going after a loss?", "grief");
    addResponse("grief", "Should we speak of them?",
        "@S@'When the living are ready. A name remembered honestly "
        "is better than a silence forced by discomfort.'");
    addResponseTopic("grief", "Should we speak of them?", "the fallen");
    addResponse("scions of dhuras", "Why does their safety matter to us?",
        "@S@'Every ally we protect is a promise kept. Their return "
        "could also strengthen the trust between our orders.'");
    addResponseTopic("scions of dhuras",
        "Why does their safety matter to us?", "the Scions");
    addResponse("the Scions", "What should I tell them?",
        "@S@'Tell them what happened plainly and let them decide "
        "how they will answer it.'");
    addResponseTopic("the Scions", "What should I tell them?",
        "the company");
}
