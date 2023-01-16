class Memes{
    //private meme: string;
    private memes: string[] = [];
    constructor(private readonly meme:string) {
        //this.meme = n;
    }

    describe() {
        console.log('80 hazar ka jutta,' + this.meme);
    }

    addMeme(new_meme:string){
        this.memes.push(new_meme);
    }

    printAllMemes(){
        console.log(this.memes);
    }
}

const shoes = new Memes("Tera ghar jainga");

shoes.describe();
shoes.addMeme("Smooth Tanmay bhai Smooth")
shoes.addMeme("Wahh wahh wahh wahh!")
shoes.printAllMemes();

class Memes2 extends Memes{
     creator:string;
     constructor(meme:string, c:string){
        super(meme);
        this.creator=c;
     }
} 

const shoes2 = new Memes2("youth icon!","People")

shoes2.describe();
shoes2.addMeme("Smooth Tanmay bhai Smooth")
shoes2.addMeme("Wahh wahh wahh wahh!")
shoes2.printAllMemes();
