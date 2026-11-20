//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/areas/minlach/characters/quest-conversation.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addTopic("first conversation", "@D@Fennel marks a line on his slate "
        "before looking up.");
    addTopic("the quay", "@S@'The quay is small, but the water is deep "
        "enough for the local fleet. Larger ships anchor outside and "
        "lighter craft bring their cargo in.'");
    addTopic("harbor records", "@D@Fennel taps the slate with his "
        "chalk. @S@'Every cargo is weighed and entered here. It keeps "
        "the merchants honest and lets me tell whether a delay is "
        "weather, poor planning, or something worth reporting.'");
    addTopic("coastal weather", "@S@'The sea can turn quickly. A "
        "captain who ignores the wind will lose more than a day, so "
        "we watch the water before we promise a delivery.'");
    addTopic("manifest checks", "@D@Fennel turns the slate around. "
        "@S@'The manifest lists what was loaded, what was unloaded, "
        "and who accepted it. If those numbers differ, I check the "
        "entries before accusing anyone.'");
    addTopic("late cargo", "@S@'A late ship may be delayed by weather, "
        "damage, or a change of destination. I ask the captain before "
        "I mark a cargo missing.'");

    addResponse("first conversation", "What comes through the harbor?",
        "@S@'Fish, lumber, salt, and whatever the northern farms can spare.'");
    addResponseTopic("first conversation", "What comes through the harbor?",
        "the quay");
    addResponse("first conversation", "Are you the harbor master?",
        "@S@'A factor. I keep the accounts, check the cargo, and "
        "settle arguments about weight. The captains decide where "
        "their ships sail.'");
    addResponse("first conversation", "Can I help with a shipment?",
        "@S@'If you are carrying a manifest, bring it here. If you "
        "are looking for work, ask the captains at the quay.'");
    addResponse("the quay", "Why do the large ships stay offshore?",
        "@S@'The water is deep, but the quay is not built for their "
        "draft. The lighters are slower, but they keep the harbor "
        "from losing cargo to a careless landing.'");
    addResponseTopic("the quay", "Why do the large ships stay offshore?",
        "harbor records");
    addResponse("harbor records", "What delays the ships most?",
        "@S@'Weather first, damaged rigging second. A missing cargo "
        "is rare, and when one happens I check the books before I "
        "accuse anyone.'");
    addResponseTopic("harbor records", "What delays the ships most?",
        "coastal weather");
    addResponse("first conversation", "How do you prevent cargo disputes?",
        "@S@'We record each transfer and have the receiving party "
        "check the count. Good records protect honest merchants.'");
    addResponseTopic("first conversation",
        "How do you prevent cargo disputes?", "manifest checks");
    addResponse("manifest checks", "What if the counts do not agree?",
        "@S@'We recount and compare the marks on each crate. "
        "If the difference remains, I ask both parties to explain.'");
    addResponseTopic("manifest checks",
        "What if the counts do not agree?", "harbor records");
    addResponse("coastal weather", "What happens when a ship is late?",
        "@S@'I check the harbor and ask the captains. A delay is "
        "not proof that cargo or crew are lost.'");
    addResponseTopic("coastal weather",
        "What happens when a ship is late?", "late cargo");
    addResponse("late cargo", "When do you report a missing ship?",
        "@S@'When the captain or the schedule gives reason to worry. "
        "I record what we know and leave rumor out of the report.'");
    addResponseTopic("late cargo",
        "When do you report a missing ship?", "manifest checks");

    addTopic("cargo briefing", "@D@Fennel rests his chalk on the slate. "
        "@S@'A fish delivery is short by weight. The buyer wants the "
        "carter charged, but I will not sign that accusation unchecked.'");
    addResponseTopic("first conversation", "Can I help with a shipment?",
        "cargo briefing");
    addTopic("cargo method", "@S@'Start with the manifest in the "
        "warehouse east of here. Then check Sella's market scales and "
        "the dock tally here at the quay. Use investigate with the "
        "name written beside each record.'");
    addResponse("cargo briefing", "Where should I begin?",
        "@D@You ask which records can settle the dispute.");
    addResponseTopic("cargo briefing", "Where should I begin?", "cargo method");
    addResponse("cargo briefing", "Could the carter have stolen it?",
        "@D@Fennel's mouth tightens. @S@'Possibly. That is a question, "
        "not a finding. Check the containers as well as the numbers.'");
    addResponseTopic("cargo briefing", "Could the carter have stolen it?",
        "cargo method");
    addTopic("cargo accepted", "@S@'Good. Bring me an account I can "
        "put my name to. Do not promise the buyer an arrest.'");
    addTopicEvent("cargo accepted", "minlachBeginCargo");
    addResponse("cargo method", "I will check the delivery.",
        "@D@You agree to examine the manifest, scales, and tally.");
    addResponseTopic("cargo method", "I will check the delivery.",
        "cargo accepted");
    addResponse("cargo method", "I need to prepare first.",
        "@S@'Then prepare. A rushed accusation will not improve "
        "either the fish or the accounts.'");
    addTopic("cargo settlement", "@D@Fennel reads your account twice. "
        "@S@'Lost brine and a split hoop. That explains the weight, "
        "though somebody still has to pay for a poor delivery.'");
    addResponse("first conversation", "I checked the disputed delivery.",
        "@D@You explain the manifest, sound scales, and damaged barrels.");
    gateQuestResponse("first conversation", "I checked the disputed delivery.",
        "short-weight-cargo", "ready");
    addResponseTopic("first conversation", "I checked the disputed delivery.",
        "cargo settlement");
    addTopic("cargo restitution", "@D@Fennel rules a fresh line. "
        "@S@'Corrected weights, shared repair costs, no theft charge. "
        "I can take that to both parties.'");
    addTopicEvent("cargo restitution", "settleCargoCosts");
    addTopic("cargo damage filed", "@D@Fennel sets aside a clean sheet. "
        "@S@'A formal damage record it is. Neither party loses the "
        "right to have it reviewed.'");
    addTopicEvent("cargo damage filed", "recordCargoDamage");
    addResponse("cargo settlement", "Share the repair costs fairly.",
        "@D@You propose restitution without a criminal accusation.");
    addResponseTopic("cargo settlement", "Share the repair costs fairly.",
        "cargo restitution");
    addResponse("cargo settlement", "Record the damage for review.",
        "@D@You ask for a formal record rather than a private bargain.");
    addResponseTopic("cargo settlement", "Record the damage for review.",
        "cargo damage filed");
    addConditionalTopicAddendum("first conversation", "cargo remembered", ([
        "/areas/minlach/quests/short-weight-cargo.c":(["type":"quest"])
    ]), " @D@He taps the corrected delivery account. @S@'Your "
        "investigation kept an honest account from becoming a careless charge.'");
}
