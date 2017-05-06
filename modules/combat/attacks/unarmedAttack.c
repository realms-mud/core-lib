inherit "/lib/modules/combat/attacks/baseAttack.c";

public void init()
{
    ::init();
    setDamageType("unarmed");
    addHitDictionary(({
        "punch", "slam", "pound", "jab", "crush", "batter", "pummel", "strike",
        "slap", "cuff", "swat", "thump" }));

    addSimileDictionary(({
        "right in the ##BodyPart##", "ferociously", "with a bone-crunching force",
        "resoundingly" }));
        
    addMissMessage("##AttackerName## ##Infinitive::shadowbox##!");
    
    addHitMessage("##AttackerName## ##HitDictionary## ##TargetName## "
        "##SimileDictionary##.", "1-50");
}



