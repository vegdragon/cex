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


    @IBAction func runIt(_ sender: Any)
    {
        let solution = String(cString: generateCards())

        DispatchQueue.global(qos: DispatchQoS.QoSClass.userInitiated).async
        {
            DispatchQueue.main.async
            {
                self.lblFormular.text = solution
            }
        }
    }
}

