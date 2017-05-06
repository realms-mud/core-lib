inherit "/lib/modules/combat/attacks/baseAttack.c";

public void init()
{
    ::init();
    setDamageType("physical");
    addHitDictionary(({
        "poke", "pierce", "impale", "puncture" }));

    addSimileDictionary(({
        "in ##TargetPossessive## ##BodyPart##", "repeatedly in "
        "the ##BodyPart##", "with a ##BodyPart##-splitting force" }));
        
    addMissMessage("##AttackerName## ##Infinitive::snap## ##AttackerPossessive##"
        " mandibles at the air.");
    
    addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
        "##SimileDictionary## with ##AttackerPossessive## mandibles.",
        "1-50");
}




