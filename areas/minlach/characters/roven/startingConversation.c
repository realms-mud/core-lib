//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/areas/minlach/characters/quest-conversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@S@'Come in and warm yourself. "
        "There's room by the fire if you have news to share.'");
    addTopic("the coast road", "@S@'The north road is safe enough in "
        "company. The wooded stretch is quieter than the fields, and "
        "that's not always a comfort.'");
    addTopic("the inn", "@D@Roven glances around the common room. "
        "@S@'Travelers bring the best news, but they need a place to "
        "rest before they can tell it. I keep beds dry, food warm, "
        "and arguments short.'");
    addTopic("roadside rumors", "@S@'The coast brings salt and fish. "
        "The road brings stories, and not all of them agree. I "
        "listen, but I do not send anyone into danger on a rumor.'");
    addTopic("winter lodging", "@D@Roven checks the hearth before "
        "answering. @S@'In cold weather I keep an extra blanket "
        "near the fire. If a traveler cannot pay, we can still "
        "find a safe place for the night.'");
    addTopic("travelers' accounts", "@S@'I ask where a traveler "
        "heard a story and when. A second account can help, but "
        "three repetitions of the same rumor are still one rumor.'");

    addResponse("first conversation", "Is there room for the night?",
        "@S@'If you can pay for a bed, I can find you one.'");
    addResponse("first conversation", "How is the road north?",
        "@S@'Ask the constable before you ride out. His patrols know "
        "which tracks are fresh.'");
    addResponse("first conversation", "What is there to eat?",
        "@S@'Stew, bread, and fish when the boats have had a good "
        "day. Sit down and I will bring you a bowl.'");
    addResponseTopic("first conversation", "What is there to eat?",
        "the inn");
    addResponse("the coast road", "What should I watch for?",
        "@S@'Keep your eyes on the track and do not follow a stranger "
        "off it. If you see something troubling, turn back and tell "
        "the constable.'");
    addResponseTopic("the coast road", "What should I watch for?",
        "roadside rumors");
    addResponse("roadside rumors", "Have you heard anything useful?",
        "@S@'A sailor mentioned a rough patch of weather farther up "
        "the coast. That is all I can vouch for. Ask Fennel what the "
        "harbor records say before you plan a voyage.'");
    addResponse("the inn", "Do many travelers stop here?",
        "@S@'Enough to keep the lamps lit. Most are decent folk, "
        "and I remember the ones who treat the town well.'");
    addResponse("first conversation", "What if I cannot pay for a bed?",
        "@S@'Tell me plainly. We can find a place by the fire for "
        "one night, though I cannot promise a private room.'");
    addResponseTopic("first conversation",
        "What if I cannot pay for a bed?", "winter lodging");
    addResponse("winter lodging", "Can I repay you with work?",
        "@S@'If there is a useful task, we can agree on it in "
        "the morning. Rest first and do not leave without speaking "
        "to me.'");
    addResponseTopic("winter lodging",
        "Can I repay you with work?", "the inn");
    addResponse("roadside rumors", "How do you judge a traveler's story?",
        "@S@'I ask who saw it, where, and when. Then I wait for "
        "another account before I tell anyone to change their plans.'");
    addResponseTopic("roadside rumors",
        "How do you judge a traveler's story?", "travelers' accounts");
    addResponse("travelers' accounts", "What should I do with a warning?",
        "@S@'Tell the constable what you know and what you only "
        "heard. Let the watch decide whether it can be checked.'");
    addResponseTopic("travelers' accounts",
        "What should I do with a warning?", "the coast road");

    addTopic("carter briefing", "@D@Roven looks toward the stable door. "
        "@S@'My carter and his apprentice missed their return. "
        "They used the old mill road. I need facts before I send "
        "a search party into the woods.'");
    addResponse("first conversation", "Is someone missing on the road?",
        "@D@You ask why he keeps watching the door.");
    addResponseTopic("first conversation", "Is someone missing on the road?",
        "carter briefing");
    addTopic("carter route", "@S@'Go west through the common, then "
        "north past the stream to the old road. Check the broken "
        "cart by the waymarker, the tracks north of it, and the "
        "mill shelter. Investigate each in that order.'");
    addResponse("carter briefing", "Which route did they take?",
        "@D@You ask for landmarks rather than rumors.");
    addResponseTopic("carter briefing", "Which route did they take?",
        "carter route");
    addResponse("carter briefing", "Should I arm a rescue party?",
        "@S@'First find out whether they need rescuing from people, "
        "weather, or a broken wheel. Do not turn a delay into a battle.'");
    addResponseTopic("carter briefing", "Should I arm a rescue party?",
        "carter route");
    addTopic("carter accepted", "@S@'Keep yourself safe. People "
        "matter more than the delivery.'");
    addTopicEvent("carter accepted", "minlachBeginCarter");
    addResponse("carter route", "I will look for them.",
        "@D@You agree to check the route and return with a location.");
    addResponseTopic("carter route", "I will look for them.", "carter accepted");
    addResponse("carter route", "Not until I am ready.",
        "@D@Roven nods and keeps the route marked on his slate.");
    addTopic("carter return", "@D@Roven lets out his breath. "
        "@S@'At the farm, alive, but unable to walk back. Now we "
        "can send the right help instead of guessing.'");
    addResponse("first conversation", "I located the missing carter.",
        "@D@You explain the wheel, crutch tracks, and shelter note.");
    gateQuestResponse("first conversation", "I located the missing carter.",
        "last-waymarker", "ready");
    addResponseTopic("first conversation", "I located the missing carter.",
        "carter return");
    addTopic("carter wagon arranged", "@S@'I will hire the farm "
        "wagon and collect them. The cargo can wait.'");
    addTopicEvent("carter wagon arranged", "arrangeCarterWagon");
    addTopic("carter watch arranged", "@S@'I will give Tristan "
        "the location and request a recovery escort, not an arrest.'");
    addTopicEvent("carter watch arranged", "requestCarterWatch");
    addResponse("carter return", "Hire the farm wagon.",
        "@D@You suggest practical transport for the injured carter.");
    addResponseTopic("carter return", "Hire the farm wagon.",
        "carter wagon arranged");
    addResponse("carter return", "Ask the watch to assist.",
        "@D@You recommend a guarded recovery with the location recorded.");
    addResponseTopic("carter return", "Ask the watch to assist.",
        "carter watch arranged");

    addTopic("household briefing", "@D@Roven lowers his voice. "
        "@S@'A traveling household is stranded until its boat is "
        "repaired. I can make room, but we need an honest arrangement.'");
    addResponse("first conversation", "Who needs a place to stay?",
        "@D@You ask about the blankets folded behind the bar.");
    addResponseTopic("first conversation", "Who needs a place to stay?",
        "household briefing");
    addTopic("household route", "@S@'Read their account on the "
        "notice table here. Check the common granary west of town, "
        "then the household work board here. Stored food is available "
        "even when the gardens cannot be harvested.'");
    addResponse("household briefing", "What can they contribute?",
        "@S@'They have useful skills. I will not decide the value "
        "of their work without hearing what they can actually do.'");
    addResponseTopic("household briefing", "What can they contribute?",
        "household route");
    addResponse("household briefing", "Can the town feed them?",
        "@D@You ask about stores rather than a seasonal gathering errand.");
    addResponseTopic("household briefing", "Can the town feed them?",
        "household route");
    addTopic("household accepted", "@S@'Keep their affairs out "
        "of the market gossip. Bring back a workable choice.'");
    addTopicEvent("household accepted", "minlachBeginLodging");
    addResponse("household route", "I will check their needs and the stores.",
        "@D@You agree to help with the arrangement.");
    addResponseTopic("household route",
        "I will check their needs and the stores.", "household accepted");
    addResponse("household route", "Let me return later.",
        "@D@Roven leaves the account on the notice table.");
    addTopic("household settlement", "@S@'Two nights, provisions, "
        "and suitable paid work. We can settle this without "
        "binding them to a debt they cannot understand.'");
    addResponse("first conversation", "I checked the household's options.",
        "@D@You compare their needs, the reserve, and the work notices.");
    gateQuestResponse("first conversation", "I checked the household's options.",
        "warm-room", "ready");
    addResponseTopic("first conversation", "I checked the household's options.",
        "household settlement");
    addTopic("lodging work arranged", "@D@Roven writes down the "
        "rate and the two-night limit. @S@'Paid mending and tally "
        "work, with lodging credited fairly.'");
    addTopicEvent("lodging work arranged", "arrangeLodgingWork");
    addTopic("lodging aid arranged", "@S@'The relief fund is "
        "for a need like this. Their names need not become entertainment.'");
    addTopicEvent("lodging aid arranged", "arrangeLodgingAid");
    addResponse("household settlement", "Agree on paid work.",
        "@D@You propose a clearly bounded work exchange.");
    addResponseTopic("household settlement", "Agree on paid work.",
        "lodging work arranged");
    addResponse("household settlement", "Use the community relief arrangement.",
        "@D@You recommend aid without a debt.");
    addResponseTopic("household settlement",
        "Use the community relief arrangement.", "lodging aid arranged");
}
