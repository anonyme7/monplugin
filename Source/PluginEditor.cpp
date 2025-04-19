/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "AdditionComponent.h"
#include "ConstanteComponent.h"

//==============================================================================
MonpluginAudioProcessorEditor::MonpluginAudioProcessorEditor (MonpluginAudioProcessor& p): AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (800, 800);
}

MonpluginAudioProcessorEditor::~MonpluginAudioProcessorEditor()
{
}

//==============================================================================
void MonpluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (juce::FontOptions (15.0f));
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void MonpluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void  MonpluginAudioProcessorEditor::mouseDown(const juce::MouseEvent& event)
{
    // Vérifier si c'est un clic droit
    if (event.mods.isRightButtonDown())
    {
        // Créer un menu contextuel
        juce::PopupMenu menu;

        // Ajouter des options au menu
        menu.addItem(1, "addition");
        menu.addItem(2, "Option 2");
        menu.addSeparator(); // Ajoute une ligne de séparation
        menu.addItem(3, "Option 3");

        // Afficher le menu et gérer la sélection
        menu.showMenuAsync(juce::PopupMenu::Options().withTargetComponent(this)
            .withMousePosition(),
            [this, event](int result)
            {
                // Gérer le choix de l'utilisateur
                if (result == 1)
                {
                    AdditionComponent* additionComp = new AdditionComponent();
                    additionComp->setSize(50, 50);
                    // Positionne le composant à l'endroit du clic
                    additionComp->setTopLeftPosition(event.getPosition().x, event.getPosition().y);
                    additionComponents.add(additionComp);
                    addAndMakeVisible(additionComp);
                }
                if (result == 2)
                {
                    ConstanteComponent* constanteComp = new ConstanteComponent();
                    constanteComp->setSize(50, 50);
                    constanteComp->setTopLeftPosition(event.getPosition().x, event.getPosition().y);
                    constanteComponents.add(constanteComp);
                    addAndMakeVisible(constanteComp);
                }
                if (result == 3)
                {
                    juce::Logger::writeToLog("Option 3 sélectionnée");
                    // Ajoutez votre logique ici
                }
            });
    }

}

void MonpluginAudioProcessorEditor::childComponentClicked(juce::Component* component)
{
    // Désélectionner l'ancien composant
    if (selectedComponent != nullptr)
    {
        if (auto* addComp = dynamic_cast<AdditionComponent*>(selectedComponent))
            addComp->setSelected(false);
        else if (auto* constComp = dynamic_cast<ConstanteComponent*>(selectedComponent))
            constComp->setSelected(false);
    }

    // Sélectionner le nouveau composant
    selectedComponent = component;
    if (auto* addComp = dynamic_cast<AdditionComponent*>(component))
        addComp->setSelected(true);
    else if (auto* constComp = dynamic_cast<ConstanteComponent*>(component))
        constComp->setSelected(true);
}


void MonpluginAudioProcessorEditor::removeAdditionComponent(AdditionComponent* comp)
{
    additionComponents.removeObject(comp); // Supprime et détruit le composant
}

void MonpluginAudioProcessorEditor::removeConstanteComponent(ConstanteComponent* comp)
{
    constanteComponents.removeObject(comp); // Supprime et détruit le composant
}
