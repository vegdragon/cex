//
//  ViewController.swift
//  24Points
//
//  Created by Wu Jian on 09/11/2016.
//  Copyright © 2016 Baresi. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var lblNumbers: UILabel!
    
    @IBOutlet weak var lblFormular: UILabel!
    
    @IBOutlet weak var btnRunit: UIBarButtonItem!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        btnRunit.title = "RunIt"
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    @IBAction func runIt(_ sender: Any)
    {
        generateCards();
    }

}

