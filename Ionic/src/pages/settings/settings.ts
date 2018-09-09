import { Component } from '@angular/core';
import { NavController } from 'ionic-angular';
import { SettingsProvider } from '../../providers/setting/setting';

@Component({
  selector: 'page-settings',
  templateUrl: 'settings.html',
})
export class SettingsPage {
  selectedTheme: String;

  constructor(
    public navCtrl: NavController,
    private settings: SettingsProvider
  ) { }

  toggleAppTheme() {
    this.settings.setActiveTheme('dark-theme');
  }

  appLightTheme() {
    this.settings.setActiveTheme('light-theme');
  }
}
